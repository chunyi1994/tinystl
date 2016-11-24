#include <iostream>
#include "algorithm.h"
#include "allocate.h"
#include "iterator.h"
#include "shared_ptr.h"
#include "utility.h"
#include "strings.h"
#include "mutex_lock.h"
#include "condition.h"
#include "string_ver_1.h"
#include "queue.h"
#include "stack.h"
#include "thread.h"
#include "ci_string.h"
#include <vector>
#include <unistd.h>
using namespace std;
using namespace tinystl;

int main(){
    vector<int> vec(10);
    int n = 0;
    std::generate(vec.begin(), vec.end(), [&n]() {
        n = n + 2;
        return n;
    });

    auto iter = tinystl::binary_search(vec.begin(), vec.end(), 99);
    if(iter == vec.end()){
        cout<<"not found"<<endl;
    } else {
        cout<<"found"<<endl;
    }

    iter = tinystl::binary_search(vec.begin(), vec.end(), 3);
    if(iter == vec.end()){
        cout<<"not found"<<endl;
    } else {
        cout<<"found"<<endl;
    }

    iter = tinystl::binary_search(vec.begin(), vec.end(), 0);
    if(iter == vec.end()){
        cout<<"not found"<<endl;
    }    else {
        cout<<"found"<<endl;
    }

    iter = tinystl::binary_search(vec.begin(), vec.end(), 9);
    if(iter == vec.end()){
        cout<<"not found"<<endl;
    }    else {
        cout<<"found"<<endl;
    }


}



