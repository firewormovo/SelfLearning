#include "ttpl.h"

namespace TTPL {
ThreadPool::ThreadPool() {}

ThreadPool::ThreadPool(const ThreadPoolConfig& config) : config_(config) {
  this->total_function_num_.store(0);
  this->waiting_thread_num_.store(0);

  this->thread_id_.store(0);
  this->is_shutdown_.store(false);
  this->is_shutdown_now_.store(false);
  if (IsValidConfig(config_)) {
    is_available_.store(true);
  } else {
    is_available_.store(false);
  }
}

ThreadPool::~ThreadPool() { ShutDown(); }

// bool ThreadPool::Reset(const ThreadPoolConfig& config) {
//   if (!IsValidConfig(config_)) {
//     return false;
//   }
//   if (config_.core_threads != config.core_threads) {
//     return false;
//   }
//   config_ = config;
//   return true;
// }

// bool ThreadPool::Start() {
//   if (!IsAvailable()) {
//     return false;
//   }
//   int core_thread_num = config_.core_threads;
//   std::cout << "Init thread num :" << core_thread_num << std::endl;
//   while (core_thread_num-- > 0) {
//     AddThread(GetNextThreadId());
//   }
//   return true;
// }

void ThreadPool::ShutDown() { ShutDown(false); }

void ThreadPool::ShutDown(const bool is_now) {
  if (this->is_available_.load()) {
    if (is_now) {
      this->is_shutdown_now_.store(true);
    } else {
      this->is_shutdown_.store(true);
    }
    this->task_cv_.notify_all();
    this->is_available_.store(false);
  }
}

void ThreadPool::ShutDownNow() { ShutDown(true); }

int ThreadPool::GetWaitingThreadSize() {
  return this->waiting_thread_num_.load();
}

int ThreadPool::GetTotalThreadSize() { return this->worker_threads_.size(); }

int ThreadPool::GetRunnedFuncNum() { return this->total_function_num_.load(); }

bool ThreadPool::IsValidConfig(const ThreadPoolConfig& conf) {
  if (conf.core_threads < 1 || conf.max_threads < conf.core_threads ||
      conf.time_out.count() < 1) {
    return false;
  }
  return true;
}

bool ThreadPool::IsAvailable() { return this->is_available_.load(); }

// void ThreadPool::AddThread(const int id) { AddThread(id, ThreadFlag::CORE); }

void ThreadPool::AddThread(const int id, const ThreadFlag& thread_flag) {
  ThreadWrapperPtr thread_ptr = std::make_shared<ThreadWrapper>();
  thread_ptr->id.store(id);
  thread_ptr->flag.store(thread_flag);
  auto func = [this, thread_ptr]() {
    for (;;) {
      std::function<void()> task;
      {
        ThreadPoolLock lock(this->task_mutex_);
        if (thread_ptr->state.load() == ThreadState::STOP) {
          break;
        }
        std::cout << "thread id " << thread_ptr->id.load() << "running start"
                  << std::endl;

        thread_ptr->state.store(ThreadState::WAITING);
        ++this->waiting_thread_num_;
        bool is_timeout = false;
        if (thread_ptr->flag.load() == ThreadFlag::CORE) {
          this->task_cv_.wait(lock, [this, thread_ptr] {
            return (this->is_shutdown_ || this->is_shutdown_now_ ||
                    !this->tasks_.empty() ||
                    thread_ptr->state.load() == ThreadState::STOP);
          });
        } else {
          this->task_cv_.wait_for(
              lock, this->config_.time_out, [this, thread_ptr] {
                return (this->is_shutdown_ || this->is_shutdown_now_ ||
                        !this->tasks_.empty() ||
                        thread_ptr->state.load() == ThreadState::STOP);
              });
          is_timeout = !(this->is_shutdown_ || this->is_shutdown_now_ ||
                         !this->tasks_.empty() ||
                         thread_ptr->state.load() == ThreadState::STOP);
        }
        --this->waiting_thread_num_;
        if (is_timeout) {
          thread_ptr->state.store(ThreadState::STOP);
        }
        if (thread_ptr->state.load() == ThreadState::STOP) {
          break;
        }
        if (this->is_shutdown_ && this->tasks_.empty()) {
          break;
        }
        if (this->is_shutdown_now_) {
          break;
        }
        thread_ptr->state.store(ThreadState::RUNNING);
        task = std::move(this->tasks_.front());
        this->tasks_.pop();
      }
      task();
    }
  };

  thread_ptr->ptr = std::make_shared<std::thread>(std::move(func));
  // if (thread_ptr->ptr->joinable()) {
  //   thread_ptr->ptr->detach();
  // }
  // this->worker_threads_.emplace_back(std::move(thread_ptr));
}

int ThreadPool::GetNextThreadId() { return this->thread_id_++; }

// void ThreadPool::Resize(int thread_num) {
//   if (thread_num < config_.core_threads) {
//     return;
//   }
//   int old_thread_num = worker_threads_.size();
//   if (thread_num > old_thread_num) {
//     while (thread_num-- > old_thread_num) {
//       AddThread(GetNextThreadId());
//     }
//   } else {
//     int diff = old_thread_num - thread_num;
//     auto iter = worker_threads_.begin();
//     while (iter != worker_threads_.end()) {
//       if (diff == 0) {
//         break;
//       }
//       auto thread_ptr = *iter;
//       if (thread_ptr->flag.load() == ThreadFlag::CACHE &&
//           thread_ptr->state.load() == ThreadState::WAITING) {
//         thread_ptr->state.store(ThreadState::STOP);
//         --diff;
//         iter = worker_threads_.erase(iter);
//       } else {
//         ++iter;
//       }
//     }
//     this->task_cv_.notify_all();
//   }
// }

}  // namespace TTPL
