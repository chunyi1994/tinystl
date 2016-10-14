#ifndef NOCOPYABLE_H
#define NOCOPYABLE_H

namespace tinystl {

class nocopyable {
public:
    nocopyable(){}
protected:
    nocopyable(const nocopyable&);
    nocopyable operator=(const nocopyable&);
    nocopyable(nocopyable&& other);
};

}

#endif // NOCOPYABLE_H

