#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>

#include "pair.h"

using std::cout;
using  std::endl;
using std::string;

namespace tinystl {

inline void log(const string& str)
{
    cout<<str<<endl;
}

template<class Key, class Value>
inline pair<Key, Value> make_pair(Key key, Value value) {
    pair<Key, Value> new_pair(key, value);
    return new_pair;
}

}

#endif // UTILS_H

