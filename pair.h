#ifndef PAIR_H
#define PAIR_H
#include <utility>

namespace tinystl{
template<class Key, class Value>
struct pair{

    pair() {}

    Pair(Key k, Value v) :
        first(std::move(k)),
        second(std::move(v)) {}

    Key first;
    Value second;
};

}
#endif // PAIR_H

