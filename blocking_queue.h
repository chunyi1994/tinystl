#ifndef THREADSAFEQUEUE_H
#define THREADSAFEQUEUE_H

#include <mutex>
#include <condition_variable>
#include <queue>
#include <memory>
#include <utility>
using std::queue;
using std::mutex;
using std::condition_variable;
using std::lock_guard;
using std::unique_lock;
using std::move;

namespace tinystl{

template<class T>
class blocking_queue
{
    typedef T value_type;

public:
    blocking_queue():queue_(), mutex_(), cond_(){}

    void push(value_type newValue){
          lock_guard<mutex> lock(mutex_);
          queue_.push(move(newValue));
          cond_.notify_one();
      }

      bool empty() const{
          lock_guard<mutex> lock(mutex_);
          return queue_.empty();
      }

      value_type pop(){
          unique_lock<mutex> lock(mutex_);
          cond_.wait(lock, [this]{ return !queue_.empty(); });
          value_type value = std::move(queue_.front());
          queue_.pop();
          return value;
      }

    bool empty() const{
        lock_guard<mutex> lock(mutex_);
        return queue_.empty();
    }

private:
    queue<value_type> queue_;
    mutable mutex mutex_;
    condition_variable cond_;
};

}
#endif // THREADSAFEQUEUE_H
