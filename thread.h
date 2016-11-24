#ifndef THREAD_H
#define THREAD_H

#include <pthread.h>
#include <functional>

#include "nocopyable.h"

using std::function;
namespace tinystl {

typedef  function<void()> function_void;

void* thread_function(void* arg) {
    function_void* func = (function_void*) arg;
    (*func)();
    return (void*) 0;
}

class thread {
public:
    thread(const function<void()>& func) : func_(func), tid_(0) {
        pthread_create(&tid_, NULL, thread_function, (void *)&func_);
    }

    ~thread() {
    }

private:
    function<void()> func_;
    pthread_t tid_;
};


}
#endif // THREAD_H

