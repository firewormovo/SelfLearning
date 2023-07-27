#pragma once

#include <atomic>
#include <chrono>
#include <thread>
#include <mutex>

namespace TTPL {
using PoolSeconds = std::chrono::seconds;

struct ThreadPoolConfig {
  int core_threads;
  int max_threads;
  int max_task_size;
  PoolSeconds time_out;
};
/*线程的状态： 初始化、等待、运行、停止*/
enum class ThreadState { INIT = 0, WAITING = 1, RUNNING = 2, STOP = 3 };

/*线程的种类标识: cache是内部为了执行更多任务临时创建出来的*/
enum class ThreadFlag { INIT = 0, CORE = 1, CACHE = 2 };

using ThreadPtr = std::shared_ptr<std::thread>;
using ThreadId = std::atomic<int>;
using ThreadStateAtomic = std::atomic<ThreadState>;
using ThreadFlagAtomic = std::atomic<ThreadFlag>;

/*线程池存在的基本单位*/
struct ThreadWrapper {
  ThreadPtr ptr;
  ThreadId id;
  ThreadFlagAtomic flag;
  ThreadStateAtomic state;

  ThreadWrapper() {
    ptr = nullptr;
    id = 0;
    state.store(ThreadState::INIT);
  }
};

using ThreadWrapperPtr = std::shared_ptr<ThreadWrapper>;
using ThreadPoolLock = std::unique_lock<std::mutex>;
}  // namespace TTPL
