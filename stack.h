#ifndef STACK_H
#define STACK_H
#include <vector>
#include <cstddef>
#include <utility>
using std::move;
using std::vector;


template<class T>
class stack{
    typedef    T              value_type;
    typedef    T&            reference;
    typedef const T&     const_reference;
public:

    stack() : datas_(){}

    ~stack(){}

    void push(value_type value) {
        datas_.push_back(move(value));
    }

    const_reference top() const {
        return datas_.back();
    }

    void pop() {
        datas_.pop_back();
    }

    size_t size() const {
        return datas_.size();
    }

    bool empty() const {
        return datas_.empty();
    }

private:
    vector<value_type> datas_;
};

#endif // STACK_H

