#ifndef ALLOCATE_H
#define ALLOCATE_H

#include <cstddef>
#include <new>
#include <climits>
#include <iostream>

#include "memory.h"

namespace tinystl {


template<class T>
class allocator {
public:
    typedef         T         value_type;
    typedef         T*       pointer;
    typedef    const T*  const_pointer;
    typedef         T&      reference;
    typedef     size_t     size_type;
    typedef ptrdiff_t     difference_type;

    template <class U>
    struct rebind {
        typedef allocator<U> other;
    };

    static pointer allocate(size_type n) {
        return tinystl::allocate((difference_type)n, (pointer)0);
    }

    static void deallocate(pointer p, size_type) {
        tinystl::deallocate(p);
    }

    void construct(pointer p, const T&value) {
       tinystl::construct(p, value);
    }

    void destory(pointer p) {
       tinystl::destory(p);
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

template <class T, class Alloc>
class simple_alloc {
public:
    static T* allocate(size_t n) { return n == 0 ? 0 : Alloc::allocate(n * sizeof(T)); }
    static T* allocate() { Alloc::allocate(sizeof(T)); }
    static void deallocate(T* p, size_t n) { Alloc::deallocate(p, n * sizeof(T)); }
    static void deallocate(T* p) { Alloc::deallocate(p, sizeof(T)); }
};


}

#endif // ALLOCATE_H

//暂时没有用的代码
//template<class T>
//inline T* _allocate(ptrdiff_t size, T*) {
//    T* temp = (T*) (::operator new((size_t)(size * sizeof(T))));
//    if (0 == temp) {
//        //log("out of memory");
//        return nullptr;
//    }
//    return temp;
//}

//template<class T>
//inline void _deallocate(T* buffer) {
//    ::operator delete(buffer);
//}

//template<class T1, class T2>
//inline void _construct(T1 *p, const T2& value) {
//    new(p) T1(value);
//}

//template<class T>
//inline void _destory(T* p) {
//    p->~T();
//}
