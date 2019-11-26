//
// Created by Zeno on 2019/11/25.
//

#include <iostream>
#include <typeinfo>
using namespace std;

int main(){
    int* q1 = nullptr;
    int* const q2 = nullptr;
    cout<< typeid(q1).name() << endl;
    cout<< typeid(q2).name() << endl;
    return 0;
}
