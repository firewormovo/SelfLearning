#pragma once

#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <list>
#include <queue>

#include "ttpl_conf.h"
namespace TTPL {
class ThreadPool {
 private:
  ThreadPoolConfig config_;
  std::list<ThreadWrapperPtr> worker_threads_;
  std::queue<std::function<void()>> tasks_;
  std::mutex task_mutex_;
  std::condition_variable task_cv_;

  std::atomic<int> total_function_num_;
  std::atomic<int> waiting_thread_num_;
  std::atomic<int> thread_id_;  // 为新创建的线程分配的id

  std::atomic<bool> is_shutdown_now_;
  std::atomic<bool> is_shutdown_;
  std::atomic<bool> is_available_;

 private:
  bool IsValidConfig(const ThreadPoolConfig& conf);

  bool IsAvailable();

  void AddThread(const int id);

  void AddThread(const int id, const ThreadFlag& thread_flag);

  int GetNextThreadId();

  void Resize(int thread_num);

 public:
  ThreadPool();
  explicit ThreadPool(const ThreadPoolConfig& config);

  ~ThreadPool();

  bool Reset(const ThreadPoolConfig& config);

  bool Start();

  void ShutDown();

  void ShutDown(const bool is_now);

  void ShutDownNow();

  int GetWaitingThreadSize();

  int GetTotalThreadSize();

  int GetRunnedFuncNum();

  template <typename F, typename... Args>
  auto Run(F&& f, Args&&... args)
      -> std::shared_ptr<std::future<std::result_of_t<F(Args...)>>> {
    if (this->is_shutdown_.load() || this->is_shutdown_now_.load() ||
        !IsAvailable()) {
      return nullptr;
    }
    if (GetWaitingThreadSize() == 0 &&
        GetTotalThreadSize() < config_.max_threads) {
      AddThread(GetNextThreadId(), ThreadFlag::CACHE);
    }
    using return_type = std::result_of_t<F(Args...)>;
    auto task = std::make_shared<std::packaged_task<return_type()>>(
        std::bind(std::forward<F>(f), std::forward<Args>(args)...));
    total_function_num_++;

    std::future<return_type> res = task->get_future();
    {
      ThreadPoolLock lock(this->task_mutex_);
      this->tasks_.emplace([task]() { (*task)(); });
    }
    this->task_cv_.notify_one();
    return std::make_shared<std::future<std::result_of_t<F(Args...)>>>(
        std::move(res));
  }
};

}  // namespace TTPL