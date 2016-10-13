#ifndef SHARED_PTR_H
#define SHARED_PTR_H
#include "shared_ptr_data.h"
namespace tinystl {

template<class T>
class shared_ptr{
    typedef    T             value_type;
    typedef    T*            pointer;
    typedef    T&           reference;
    typedef const T&    const_reference;
    typedef shared_ptr_data<T>* data_ptr;

public:
    shared_ptr() :
        data_(NULL) {}

    shared_ptr(pointer ptr) :
        data_(new shared_ptr_data<value_type>(ptr)) {}

    shared_ptr(const shared_ptr& other) :
        data_(other.data_) {
        data_->count_++;
    }

    ~shared_ptr();

    shared_ptr& operator=(const shared_ptr& other);

    reference operator*()const {
        return *(data_->value_type_ptr_);
    }

    bool operator==(const shared_ptr& other) {
        return data_ == other.data_;
    }

    pointer get() const {
        return data_->value_type_ptr_;
    }

    pointer operator->() const {
        return data_->value_type_ptr_ ;
    }

private:
    data_ptr data_;
};

template<class T>
shared_ptr<T>&  shared_ptr<T>::operator=(const shared_ptr<T>& other) {
    if(data_ && --data_->count_ <= 0){
        delete data_;
        data_ = NULL;
    }
    data_ = other.data_;
    data_->count_++;
}

template<class T>
 shared_ptr<T>::~shared_ptr() {
    if(data_ && --data_->count_ <= 0){
        delete data_;
        data_ = NULL;
    }
}



}

#endif // SHARED_PTR_H

