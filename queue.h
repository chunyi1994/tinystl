#ifndef QUEUE_H
#define QUEUE_H

#include <list>
#include <queue>
#include <utility>
#include <cstddef>
using std::move;
using std::list;

namespace tinystl {

template<class T>
class queue {
    typedef    T              value_type;
    typedef    T&            reference;
    typedef const T&     const_reference;
public:
    queue() : datas_() {}

    void push(value_type value) {
        datas_.push_back(move(value));
    }

    void pop() {
        datas_.pop_front();
    }

    bool empty() const {
        return datas_.empty();
    }

    const_reference front() const {
        return datas_.front();
    }

    const_reference back() const {
        return datas_.back();
    }

    size_t size() const {
        return datas_.size();
    }

private:
    list<value_type> datas_;
};

}
#endif // QUEUE_H

