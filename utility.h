#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>

using std::cout;
using  std::endl;
using std::string;

namespace tinystl {

inline void log(const string& str)
{
    cout<<str<<endl;
}

}

#endif // UTILS_H

