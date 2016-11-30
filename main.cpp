#include <iostream>
#include <vector>
#include <algorithm>
#include "vector.h"
#include "algobase.h"
using namespace std;
using namespace tinystl;
int main()
{
   tinystl::vector<int> vec;
   vec.push_back(10);
   vec.push_back(10);
   vec.push_back(10);
   vec.insert(vec.begin(), 3);

   for(auto &w : vec) {
       cout<<w<<endl;
   }

   cout << "Hello World!" << endl;
    return 0;
}

