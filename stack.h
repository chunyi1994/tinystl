#ifndef STACK_H
#define STACK_H
#include <vector>
#include <cstddef>

using std::vector;
template<class T>

class stack{
public:

    stack() : datas_(){}

    ~stack(){}

    void push(const T& value) {
        datas_.push_back(value);
    }

    T top() {
        return datas_.back();
    }

    void pop() {
        datas_.pop_back();
    }

    size_t size() {
        return datas_.size();
    }

private:
    vector<T> datas_;
};

#endif // STACK_H

