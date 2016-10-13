#ifndef ITERATOR_H
#define ITERATOR_H
#include <assert.h>

#include "iterator_traits.h"

namespace tinystl {

template<class Category, class T, class Distance = ptrdiff_t,
         class Pointer = T*, class Reference = T&>
struct iterator {
    typedef   Category      iterator_category;
    typedef      T                 value_type;
    typedef    Distance      difference_type;
    typedef    Pointer        pointer;
    typedef    Reference   reference;
};

template<class Iterator>
inline typename iterator_traits<Iterator>::difference_type
_distance(Iterator begin, Iterator end, input_iterator_tag) {
    typedef typename iterator_traits<Iterator>::difference_type difference_type;
    difference_type n = 0;
    for(;begin != end; begin++) {
        n++;
    }
    return n;
}

template<class Iterator>
inline typename iterator_traits<Iterator>::difference_type
_distance(Iterator begin, Iterator end, random_access_iterator_tag) {
    return end - begin;
}

template <class Iterator>
inline typename iterator_traits<Iterator>::difference_type
distance(Iterator begin, Iterator end) {
    return _distance(begin, end, iterator_category(begin));
}

template<class Iterator, class Distance>
inline void _advance(Iterator& iter, Distance n, random_access_iterator_tag) {
    iter += n;
}

template<class Iterator, class Distance>
inline void _advance(Iterator& iter, Distance n, bidirectional_iterator_tag) {
    if(n > 0) {
        while(n--) {
            iter++;
        }
    } else {
        while(n++) {
            iter--;
        }
    }
}

template<class Iterator, class Distance>
inline void _advance(Iterator& iter, Distance n, input_iterator_tag) {
    while(n--) {
        iter++;
    }
}

template<class Iterator, class Distance>
inline void advance(Iterator& iter, Distance n, bidirectional_iterator_tag) {
    _advance(iter, n, iterator_category(iter));
}

}
#endif // ITERATOR_H

