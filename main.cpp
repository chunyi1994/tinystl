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

#include <vector>
#include <unistd.h>
using namespace std;
using namespace tinystl;

mutex mutex_;
condition cond_(mutex_);

void run() {
    cout<<"hello" <<endl;
    cout<<"hahahha"<<endl;
}


int main(){
    thread t(run);
    sleep(5);
}



