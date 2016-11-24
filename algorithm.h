#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <algorithm>
#include "iterator.h"
namespace tinystl {

template<class InputIterator1, class InputIterator2>
inline bool equal(InputIterator1 iter1_begin, InputIterator1 iter1_end, InputIterator2 iter2) {
    while(iter1_begin != iter1_end) {
        if(*iter1_begin != *iter2) {
            return false;
        }
        iter1_begin++;
        iter2++;
    }
    return true;
}

template<class InputIterator, class OutputIterator>
inline OutputIterator copy(InputIterator begin, InputIterator end, OutputIterator dest_begin) {
    while(begin != end) {
        *dest_begin = *begin;
        begin++;
        dest_begin++;
    }
    return dest_begin;
}

template <class Iterator, class Value>
inline Iterator binary_search(Iterator begin, Iterator end, Value find_value) {
    Iterator notFound = end;
    Iterator mid;
    typename Iterator::difference_type distance_n;
    while(end - begin > 0) {
        distance_n = end - begin;
        mid = begin;
        mid += distance_n / 2;
        if(find_value > *mid) {
            begin = mid + 1;
        }else if(find_value == *mid) {
            return mid;
        }else {
            end = mid - 1;
        }
    }

    if(* begin != find_value) {
        return notFound;
    } else {
        return begin;
    }
}

template <class Iterator, class T>
inline T accumulate(Iterator begin, Iterator end, T init) {
    while(begin != end) {
        init += *begin;
        begin++;
    }
    return init;
}

template <class Iterator, class T, class Func>
inline T accumulate(Iterator begin, Iterator end, T init, Func func) {
    while(begin != end) {
        func(init, *begin);
        begin++;
    }
    return init;
}

template <class Iterator, class Function>
inline void generate_n(Iterator begin, size_t n, Function func) {
    while(n--) {
        *begin = func();
        begin++;
    }
}

template <class Iterator, class Function>
inline void generate(Iterator begin, Iterator end, Function func) {
    while(begin != end) {
        *begin = func();
        begin++;
    }
}

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

