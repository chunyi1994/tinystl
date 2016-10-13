#ifndef SHARED_PTR_DATA_H
#define SHARED_PTR_DATA_H
#include <cstddef>
namespace tinystl {

template<class T>
class shared_ptr_data {
    typedef    T*    pointer;
    typedef    T      value_type;
public:
    shared_ptr_data(pointer value, size_t count = 1) :
        value_type_ptr_(value), count_(count) { }

    ~shared_ptr_data() {
        delete value_type_ptr_;
    }

    pointer value_type_ptr_;
    size_t count_;
};


}

#endif // SHARED_PTR_DATA_H

