//
// Created by Zeno on 2019/10/27.
//

#include <time.h>
#include <iostream>
using namespace std;
struct A{
    int a[10000];
};
A a;
A TestFunc1(){
    return a;
}
A& TestFunc2(){
    return a;
}
void TestReturnByRefOrValue(){
    //以值作为函数的返回值类型
    size_t begin1 = clock();
    for(size_t i = 0;i < 10000;++i)
        TestFunc1();
    size_t end1 = clock();

    //以引用作为函数的返回值类型
    size_t begin2 = clock();
    for(size_t i = 0;i < 10000;++i)
        TestFunc2();
    size_t end2 = clock();

    //计算两个函数运算完成之后的时间
    cout<<"TestFunc1 time:"<<end1 - begin1 <<endl;
    cout<<"TestFunc2 time:"<<end2 - begin2 <<endl;
}
int main(){
    //测试运行10次，值和引用作为返回值效率方面的区别
    for(int i =0;i < 10;++i){
        TestReturnByRefOrValue();
    }
    return 0;
}
