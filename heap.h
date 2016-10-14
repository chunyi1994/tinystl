#ifndef HEAP_H
#define HEAP_H
#include "iterator.h"
namespace tinystl {

template <class RandomAcessIterator, class T, class Distance>
inline void _make_heap(RandomAcessIterator begin,
                       RandomAcessIterator end,
                       T*, Distance*)
{
    //
}

template <class RandomAcessIterator>
inline void make_heap(RandomAcessIterator begin, RandomAcessIterator end) {
    _make_heap(begin, end, value_type(begin), difference_type(begin));
}



}

#endif // HEAP_H

