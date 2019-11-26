//
// Created by Zeno on 2019/11/26.
//

#include <iostream>
using namespace std;

class T{

};
int fun(int** a);
int fun(int *a);

int main(){
    int b = 0;
    fun(&b);
    int* p1 = &b;//一级指针
    int** p2 = &p1; //二级指针
}

int main(){
    int a = 10;
    int* p = &a;
    const int** q = &p;
    return 0;
}
