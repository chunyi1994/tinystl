#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <algorithm>
namespace tinystl {

template<class Iterator, class T>
inline void fill(Iterator begin, Iterator end, T value) {
    while(begin != end) {
        *begin = value;
        begin++;
    }
}

template<class Iterator, class T>
inline void fill_n(Iterator begin, size_t n, T value) {
    while(n--) {
        *begin = value;
        begin++;
    }
}

template <class Iterator, class T>
inline size_t count(Iterator begin, Iterator end, T value) {
    size_t n = 0;
    while(begin != end) {
        if(*begin == value) {
            n++;
        }
        begin++;
    }
    return n;
}

template <class Iterator, class Function>
inline bool count_if(Iterator begin, Iterator end, Function func) {
    size_t n = 0;
    while(begin != end) {
        if(func(*begin)){
            n++;
        }
        begin++;
    }
    return n;
 }

template <class T>
inline T max(const T& value1, const T& value2) {
    if(value1 > value2) {
        return value1;
    }

    return value2;
}

template <class T>
inline T min(const T& value1, const T& value2) {
    if(value1 < value2) {
        return value1;
    }

    return value2;
}

template<class Iterator, class Function>
inline Function for_each(Iterator begin, Iterator end, Function func) {
    for(; begin != end; begin++) {
        func(*begin);
    }
    return func;
}

template<class Itertor, class Function>
inline Itertor find_if(Itertor begin, Itertor end, Function func){
    for(;begin != end; begin++){
        if(func(*begin)){
            break;
        }
    }
    return begin;
}

template<class Iterator, class T>
inline Iterator find(Iterator begin, Iterator end, const T& value){
    for(Iterator iter = begin; iter != end; iter++){
        if(*iter == value){
            return iter;
        }
    }
    return end;
}

template<class T>
inline void swap(T& a, T& b){
    T c = a;
    a = b;
    b = c;
}

template<class Iterator1, class Iterator2, class Operation>
inline void transform(Iterator1 begin1, Iterator1 end1, Iterator2 begin2, Operation op){
    while(begin1 != end1){
        *begin2 = op(*begin1);
        begin1++;
        begin2++;
    }
}
}

#endif // ALGORITHM_H

