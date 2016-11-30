#ifndef ALGOBASE_H
#define ALGOBASE_H
#include <cstddef>

#include "iterator.h"
namespace tinystl {

template <class OutputIterator, class Size, class T>
OutputIterator fill_n(OutputIterator first, Size n, const T& value) {
    while (n--) {
        *first = value;
        ++first;
    }
    return first;
}

//todo
template <class InputIterator, class OutputIterator>
OutputIterator copy(InputIterator first, InputIterator last,
                    OutputIterator result) {
    while (first != last) {
        *result = *first;
        ++result;
        ++first;
    }
    return result;
}

template <class OutputIterator, class T>
void fill(OutputIterator begin, OutputIterator end, const T& value) {
    while (begin != end) {
        *begin = value;
        ++begin;
    }
}


template <class BidirectionalIterator1, class BidirectionalIterator2>
inline BidirectionalIterator2 copy_backward(BidirectionalIterator1 first,
                                            BidirectionalIterator1 last, BidirectionalIterator2 result) {
    while (last != first) {
        *result = *last;
        --result;
        --last;
    }
    *result = *first;
    --result;
    return result;
}

} // namespace

#endif // ALGOBASE_H

