#ifndef STRING_VER_1_H
#define STRING_VER_1_H

#include <cstddef>
#include <cstring>
#include <utility>

namespace tinystl{
//这是一个简单的string写法,通常是面试会要求写的
class String{
public:
    String();

    String(const char *p);

    String(const String &s);

    ~String();

    String& operator=(String s);

    const char& operator[](size_t pos) const;

    char& operator[](size_t pos);

    bool operator==(const String &s) const;

    size_t size() const;

    void append(const char *p, size_t len);

    void append(const String &s);

    const char* c_str() const{return data_;}

    void swap(String &str);

private:
    char* data_;
};



String::String(const char *p):data_(new char[strlen(p) + 1]){
    ::strcpy(data_, p);
}

String::String(const String &s):data_(new char[s.size() + 1]){
    ::strcpy(data_, s.c_str());
}

String::String():data_(new char[1]){
    data_[0] = '\0';
}

String& String::operator=(String s){
    swap(s);
    return *this;
}

bool String::operator==(const String &s) const{
    return ::strcmp(data_, s.c_str()) == 0;
}

void String::swap(String &str){
    std::swap(str.data_, data_);
}

size_t String::size() const{
    return strlen(data_);
}

String::~String(){
    delete[] data_;
}

void String::append(const String &s){
    size_t len = strlen(data_);
    char *newData = new char[len + s.size() + 1];
    ::strcpy(newData, data_);
    data_ = newData;
    newData = data_ + len;
    ::strcpy(newData, s.c_str());
    data_[len + s.size()] = '\0';
}

char& String::operator[](size_t pos){
    return data_[pos];
}

const char& String::operator[](size_t pos) const{
    return data_[pos];
}

//以下为测试内容,把main函数写好,再调用test,即可测试string的使用
/*
using namespace std;
using namespace tinystl;
#include <iostream>
#include <vector>
void foo(String s){
    cout<<s.c_str()<<endl;
}

String baz(){
    String st("bazk");
    return st;
}

int test(){
    String str("wodehaomama");
    foo(str);

    String st = baz();
    cout<<st.c_str()<<endl;

    vector<String> vec;
    vec.push_back("wodemama");
    vec.push_back(str);


    cout<<strlen("woai\0")<<endl;
    cout<<vec.size()<<endl;


    String my("mddy");
    my.append("wor");
    my[3] = 'b';
    cout<<my.c_str()<<endl;
    cout<<my.size()<<endl;

    const String me(my);

    char c = me[3];
    cout<<c<<endl;
}


    int main(){
        test();
    }

*/


}


#endif // STRING_VER_1_H

