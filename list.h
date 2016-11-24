#ifndef LIST_H
#define LIST_H
#include <unistd.h>
#include <assert.h>
namespace tinystl{
template<class T>
struct ListNode{
    ListNode() : next_(NULL), pre_(NULL){}
    ListNode(const T& data) : data_(data),  next_(NULL), pre_(NULL){}
    ListNode(const T& data, const ListNode* next) : data_(data),  next_(next), pre_(NULL){}
    T data_;
    ListNode *next_;
    ListNode *pre_;
};

template<class T>
class List;

template<class T>
class ListIterator{
    friend class List<T>;
public:
    ListIterator(ListNode<T>* data = NULL):data_(data){}
    bool operator==(const ListIterator& iter) const{
        return data_ == iter.data_;
    }

    bool operator!=(const ListIterator& iter) const{
        return data_ != iter.data_;
    }

    T* operator->(){
        return &(data_->data_);
    }

    T& operator*(){
        return data_->data_;
    }

    ListIterator operator--(int){
        assert(data_);
        ListIterator iter = *this;
        data_ = data_->pre_;
        return iter;
    }

    const ListIterator& operator --() const{
        assert(data_);
        data_ = data_->pre_;
        return *this;
    }

    ListIterator& operator--(){
        assert(data_);
        data_ = data_->pre_;
        return *this;
    }

    ListIterator operator++(int){
        assert(data_);
        ListIterator iter = *this;
        data_ = data_->next_;
        return iter;
    }

    ListIterator& operator ++(){
        assert(data_);
        data_ = data_->next_;
        return *this;
    }

    const ListIterator& operator ++() const{
        assert(data_);
        data_ = data_->next_;
        return *this;
    }


private:
    ListNode<T>* preNode() const{
        return data_->pre_;
    }

    ListNode<T>* node() const{
        return data_;
    }

    mutable ListNode<T>* data_;
};


template<class T>
class List
{
    typedef T ValueType;
    typedef T* Pointer;
    typedef T& Reference;
    typedef const T& ConstReference;
    typedef ListNode<T> Node;
public:
    typedef ListIterator<T> Iterator;
    typedef const ListIterator<T> ConstIterator;
    List() : begin_(NULL), end_(NULL), size_(0){
        end_ = new Node();
    }

    size_t size() const {
        return size_;
    }

    Iterator begin(){
        return begin_;
    }

    Iterator end(){
        return end_;
    }

    Iterator insert(Iterator pos, ConstReference value){
        if(pos == end_){
            pushBack(value);
            pos = end_;
            return --pos;
        }
        Node* node = new Node(value);
        if(pos == begin_){
            begin_ = node;
        }else{
            Node* pre = pos.preNode();
            pre->next_ = node;
            node->pre_ = pre;
        }
        size_++;
        Node *posNode = pos.node();
        node->next_ = posNode;
        posNode->pre_ = node;
        return node;
    }

    Iterator erase(Iterator pos){
        Node* node = pos.node();
        Node* next = node->next_;
        if(pos == begin_){
            next->pre_ = NULL;
            begin_ = next;
        }else{
            Node* pre = node->pre_;
            pre->next_ = next;
            next->pre_ = pre;
        }

        delete node;
        size_--;
        return next;
    }

    void pushBack(ConstReference value){
        Node* node = new Node(value);
        if(size_ == 0){
            begin_ = node;
        }else{
            Node* last = end_->pre_;
            last->next_ = node;
            node->pre_ = last;
        }

        end_->pre_ = node;
        node->next_ = end_;
        ++size_;
    }


private:
    Node* begin_;
    Node* end_;
    size_t size_;
};
}
#endif // LIST_H
