//
// Created by Zeno on 2019/11/27.
//
#include <iostream>
using namespace std;

int main(){
    int array[5] = {};
    int (*p)[5] = &array;
    int (&q)[5] = array;

    cout<< sizeof(array) <<endl;
    cout<< sizeof(p) <<endl;
    cout<< sizeof(q) <<endl;
    cout<< sizeof(*p) <<endl;
    return 0;
}

