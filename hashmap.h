#ifndef HASHMAP_H
#define HASHMAP_H
#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <algorithm>
#include <list>
#include <assert.h>
//#include "hashmap_iterator.h"
#include "pair.h"

using std::vector;
using std::string;
using std::list;
using std::cout;
using std::endl;
namespace tinystl{

const int HASH_DEFAULT_SIZE = 256;

template<class K, class V>
class HashMap;

template<class K>
class HashFunc{
public:
    size_t operator()(const K& key, size_t max) const{
        return key % max;
    }
};

template<class K, class V>
class IfEqualsKey {
public:
    IfEqualsKey(const K& k): k_(k){}
    bool operator () (const Pair<K,V>* ptr) {
        if(!ptr)return false;
        return k_ == ptr->first_;
    }
private:
    K k_;
};

//这是一首简单的小情歌.....哦不
//这是一个简单的string的hash算法
template<>
class HashFunc<string>{
public:
    size_t operator()(const string& key, size_t max) const{
        int size = std::min((int)key.length(), 7);
        size_t value = 0;
        for(int i = 0; i <size; i++){
            value += key[i];
        }
        int result = value % max;
        return result;
    }
};

template<class K, class V>
class HashMapIterator{
    typedef Pair<K,V>* PairPtr;
    friend class HashMap<K,V>;

public:

    bool operator==(const HashMapIterator& other) const{
        return iter_ == other.iter_;
    }

    bool operator!=(const HashMapIterator& other) const{
        return iter_ != other.iter_;
    }

    PairPtr operator->(){
        return *iter_;
    }

    Pair<K,V>& operator*(){
        return **iter_;
    }

    //调试了好久还是写错了,先删了
    HashMapIterator operator++(int){
        HashMapIterator temp = *this;
        iter_++;
        return temp;
    }

    HashMapIterator& operator++(){
        iter_++;
        return *this;
    }

private:
    HashMapIterator( typename list<PairPtr>::iterator iter) : iter_(iter){}
    typename list<PairPtr>::iterator iter_;
};

template<class K, class V>
class HashMap{
    typedef Pair<K,V>* PairPtr;
    typedef const K& ConstKeyReference;
    typedef const V& ConstValueReference;
    typedef V& ValueReference;
public:
    typedef HashMapIterator<K,V> Iterator;


    HashMap(size_t size = HASH_DEFAULT_SIZE):
        datasPool_(), hashDatas_(size), size_(0), max_(size)
    {}

    ~HashMap(){
        cout<<"~HashMap"<<endl;
        for(auto iter = datasPool_.begin(); iter != datasPool_.end(); iter++){
            delete *iter;
        }
    }

    V& operator[](ConstKeyReference key){
        size_t pos = hash_(key,max_);
        if(hashDatas_[pos].size() == 0){
            insert(key, 0);
        }

        Iterator iter = find(key);
        return iter->second_;
    }

    void insert(ConstKeyReference key, ConstValueReference value){
        size_t pos = hash_(key,max_);
        PairPtr newData = newPair(key, value);
        hashDatas_[pos].push_back(newData);
        size_++;
        if(size_ >=  max_ - 1){
            reHash();
        }
    }

    Iterator begin(){
        HashMapIterator<K,V> iter(datasPool_.begin());
        return iter;
    }

    Iterator end(){
        HashMapIterator<K,V> iter(datasPool_.end());
        return iter;
    }

    size_t size(){
        return size_;
    }

    Iterator erase(Iterator iter){
        size_t pos = hash_(iter->first_, max_);
        typename list<PairPtr>::iterator iter2;
        iter2 = std::find_if(hashDatas_[pos].begin(), hashDatas_[pos].end(), IfEqualsKey<K,V>(iter->first_));
        assert(iter2 != hashDatas_[pos].end());
        hashDatas_[pos].erase(iter2);
        size_--;
        auto iter3 = std::find_if(datasPool_.begin(), datasPool_.end(), IfEqualsKey<K,V>(iter->first_));
        delete *iter2;
        return datasPool_.erase(iter3);
    }


    Iterator find(ConstKeyReference key){
        size_t pos = hash_(key,max_);
        if(hashDatas_[pos].size() == 0){
            return end();
        }

        typename list<PairPtr>::iterator iter;
        iter = std::find_if(hashDatas_[pos].begin(),hashDatas_[pos].end(), IfEqualsKey<K,V>(key));
        if(iter ==  hashDatas_[pos].end())return end();
        return Iterator(iter);
    }

    void traverse(){
        for(size_t i = 0; i < hashDatas_.size(); i++){
            if(hashDatas_[i].size() == 0){
                continue;
            }
            for(typename list<PairPtr>::iterator iter = hashDatas_[i].begin();
                iter != hashDatas_[i].end(); iter++){
                assert(*iter);
                cout<<"*:"<<(*iter)->first_<< "   ";

            }
            cout<<endl;
        }
    }

private:

    void reHash(){
        vector<list<PairPtr> > hashDatas2(max_ * 2);
        for(size_t i = 0; i < hashDatas_.size(); i++){
            if(hashDatas_[i].size() == 0) continue;

            for(typename list<PairPtr>::iterator iter = hashDatas_[i].begin();
                iter != hashDatas_[i].end(); iter++){
                assert(*iter);
                size_t pos = hash_((*iter)->first_, max_ * 2);
                hashDatas2[pos].push_back(*iter);
            }
        }
        max_ = max_ * 2;
        hashDatas_.resize(max_);
        hashDatas_.swap(hashDatas2);
    }

    PairPtr newPair(){
        PairPtr newData = new Pair<K,V>();
        datasPool_.push_back(newData);
        return newData;
    }

    PairPtr newPair(ConstKeyReference key, ConstValueReference value){
        PairPtr newData = new Pair<K,V>(key, value);
        datasPool_.push_back(newData);
        return newData;
    }

    list<PairPtr> datasPool_;
    vector<list<PairPtr> > hashDatas_;
    size_t size_;
    size_t max_;
    HashFunc<K> hash_;
    //Iterator end_;
};
}
#endif // HASHMAP_H

