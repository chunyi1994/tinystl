#ifndef CONDITION_H
#define CONDITION_H

#include "mutex.h"

namespace tinystl {
class condition : public nocopyable {
public:
    explicit condition(mutex &mu) : mutex_(mu) {
        pthread_cond_init(&cond_, NULL);
    }

    ~condition() {
        pthread_cond_destroy(&cond_);
    }

    void wait() {
        pthread_cond_wait(&cond_, mutex_.pthread_mutex());
    }

    void notify() {
        pthread_cond_signal(&cond_);
    }

    void broadcast() {
        pthread_cond_broadcast(&cond_);
    }

private:
    mutex &mutex_;
    pthread_cond_t cond_;
};


}
#endif // CONDITION_H

