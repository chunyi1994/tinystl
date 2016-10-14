#ifndef MUTEX_H
#define MUTEX_H

#include <pthread.h>
#include <cstddef>

#include "nocopyable.h"

namespace tinystl {

class mutex : public nocopyable{
public:
    mutex() {
        pthread_mutex_init(&pthread_mutex_, NULL);
    }

    ~mutex() {
        pthread_mutex_destroy(&pthread_mutex_);
    }

    pthread_mutex_t* pthread_mutex() {
        return &pthread_mutex_;
    }

    void lock() {
        pthread_mutex_lock(&pthread_mutex_);
    }

    void unlock() {
        pthread_mutex_unlock(&pthread_mutex_);
    }

private:
    pthread_mutex_t pthread_mutex_;
};



}

#endif // MUTEX_H

