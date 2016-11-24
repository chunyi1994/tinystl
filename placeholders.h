#ifndef HOLDERPLACES_H
#define HOLDERPLACES_H
#include <typeinfo>
namespace tinystl {

template<class T>
class holder {
public:
    holder(const T& value) : held(value) {
    }

     const std::type_info & type() const {
              return typeid(T);
    }

public:
    T held;
};

}

#endif // HOLDERPLACES_H

