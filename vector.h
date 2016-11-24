#ifndef VECTOR_H
#define VECTOR_H
/*************************************************************************
  > File Name: vector.h
  > Author: Sunfish
  > Mail: 704613309@qq.com
  > Created Time: 2016年07月18日 星期一 15时14分28秒
 ************************************************************************/
#include <unistd.h>
#include <string.h>
#include <assert.h>

namespace tinystl{
template<class T>
class Vector{
    typedef T ValueType;
    typedef T* Pointer;
    typedef const T* ConstIterator;
    typedef T& Reference;
    typedef const T& ConstReference;
public:
    typedef Pointer Iterator;
    Vector():data_(NULL),begin_(NULL),end_(NULL),size_(0),max_(2)
    {
        data_ = allocate(max_);
        begin_ = data_;
        end_ = data_;
    }

    ~Vector(){
        delete[] data_;
    }

    void pushBack(ConstReference value){
        if(size_ >= max_){
            allocateNewSpace();
        }
        data_[size_] = value;
        size_++;
        end_++;
    }

    Iterator erase(Iterator iter){
        if(iter == end_ || size_ == 0){
            return end_;
        }

        Iterator it = iter + 1;

        while(it != end_){
            *(it - 1) = *it;
            it++;
        }
        size_ --;
        end_--;
        return it;
    }

    //应该是要插入以后再重新分配内存,不然会出现迭代器失效
    Iterator insert(Iterator iter, ConstReference value){
        if(iter == end_){
            pushBack(value);
            return end_-1;
        }

        Iterator it = begin_ + size_ - 1;
        while(it != iter){
            *(it + 1) = *it;
            it--;
        }

        *(it + 1) = *it;
        *it = value;
        end_++;
        size_++;
        if(size_ >= max_ - 1){
            allocateNewSpace();
        }
        return it;
    }


    size_t size() const{
        return size_;
    }

    Reference operator[](size_t pos){
        assert(pos < size_);
        return data_[pos];
    }

    Iterator begin() const{
        return begin_;
    }

    Iterator end() const{
        return end_;
    }

    ConstIterator cbegin() const{
        return begin_;
    }

    ConstIterator cend()const{
        return end_;
    }


private:
    Pointer allocate(size_t s){
        return (Pointer)new char[sizeof(ValueType) * s];
    }


    void allocateNewSpace(){
        max_ = max_ * 2;
        Pointer newP = allocate(max_);
        memcpy((void*)newP, (void*)data_, size_ * sizeof(ValueType));
        delete[] data_;
        data_ = newP;
        begin_ = data_;
        end_ = begin_ + size_;

    }

    Pointer data_;
    Iterator begin_;
    Iterator end_;
    size_t size_;
    size_t max_;
};

}
#endif // VECTOR_H

