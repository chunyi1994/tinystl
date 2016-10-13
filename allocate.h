#ifndef ALLOCATE_H
#define ALLOCATE_H

#include <cstddef>

#include "utility.h"

namespace tinystl {

template<class T>
inline T* _allocate(ptrdiff_t size, T*) {
    T* temp = (T*) (::operator new((size_t)(size * sizeof(T))));
    if (0 == temp) {
        log("out of memory");
        return NULL;
    }
    return temp;
}

template<class T>
inline void _deallocate(T* buffer) {
    ::operator delete(buffer);
}

template<class T>
inline void _construct(T *p) {
    new(p) T();
}

template<class T>
inline void _destory(T* p) {
    p->~T();
}

template<class T>
class allocator {
public:
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

    template <class U>
    struct rebind {
        typedef allocator<U> other;
    };

    pointer allocate(size_type n, const void* hint = 0) {
        return _allocate((difference_type)n, (pointer)0);
    }

    void deallocate(pointer p, size_type n) {
        _deallocate(p);
    }

    void construct(pointer p) {
        _construct(p);
    }

    void destory(pointer p) {
        _destory(p);
    }

    pointer address(reference x) {
        return (pointer) &x;
    }

    pointer const_address(reference x) {
        return (const_pointer) &x;
    }

    size_type max_size() const {
        return size_type(UINT32_MAX/sizeof(T));
    }

};

}

#endif // ALLOCATE_H

