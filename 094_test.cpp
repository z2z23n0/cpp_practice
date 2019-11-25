//
// Created by Zeno on 2019/11/25.
//
#include <stdio.h>
int main(){
    int b = 20;
    const int a = b;
    int array[a] = {};//此处编译报错！

    int* p = (int*)&a;
    *p = 30;

    printf("%d %d %d \n",a,*p,*(&a));//结果是：30 30 30
    return 0;
}

