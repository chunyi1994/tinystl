#ifndef MUTEX_LOCK_H
#define MUTEX_LOCK_H

#include "nocopyable.h"
#include "mutex.h"

namespace tinystl {

class lock_guard : public nocopyable{
public:
    explicit lock_guard(mutex& mu) : mutex_(mu) {
        mutex_.lock();
    }

    ~lock_guard() {
        mutex_.unlock();
    }

private:
    mutex &mutex_;
};

}

#endif // MUTEX_LOCK_H

