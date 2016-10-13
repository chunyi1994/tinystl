#ifndef ITERATOR_TRAITS_H
#define ITERATOR_TRAITS_H

#include <cstddef>

namespace tinystl {

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag{};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template <class T>
struct iterator_traits {
    typedef typename T::iterator_category      iterator_category;
    typedef typename T::value_type                 value_type;
    typedef typename T::difference_type        difference_type;
    typedef typename T::pointer                      pointer;
    typedef typename T::reference                  reference;
};

template <class T>
struct iterator_traits<T*> {
    typedef  random_access_iterator_tag      iterator_category;
    typedef             T                                         value_type;
    typedef         ptrdiff_t                                 difference_type;
    typedef             T*                                       pointer;
    typedef             T&                                      reference;
};

template <class T>
struct iterator_traits<const T*> {
    typedef  random_access_iterator_tag      iterator_category;
    typedef             T                                         value_type;
    typedef         ptrdiff_t                                 difference_type;
    typedef         const T*                                pointer;
    typedef         const T&                                reference;
};

template <class Iterator>
inline typename iterator_traits<Iterator>::iterator_category
iterator_category(const Iterator& iterator) {
    typedef typename iterator_traits<Iterator>::iterator_category category;
    return category();
}

template <class Iterator>
inline typename iterator_traits<Iterator>::difference_type *
difference_type (const Iterator& iterator) {
    typedef typename iterator_traits<Iterator>::difference_type  difference_type;
    return static_cast<difference_type*>(0);
}

template <class Iterator>
inline typename iterator_traits<Iterator>::value_type *
value_type (const Iterator& iterator) {
    typedef typename iterator_traits<Iterator>::value_type  value_type;
    return static_cast<value_type*>(0);
}

}

#endif // ITERATOR_TRAITS_H

