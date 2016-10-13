#include <iostream>
#include "algorithm.h"
#include "allocate.h"
#include "iterator.h"
#include "shared_ptr.h"
#include "utility.h"
#include <vector>

#include "string_ver_1.h"
using namespace std;
using namespace tinystl;

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
    return 0;
}


    int main(){
        test();
    }



