//
// Created by Zeno on 2019/10/27.
//

#include <time.h>
#include <iostream>
using namespace std;
struct A{
    int a[10000];
};

void TestFunc1(A a){

}

void TestFunc2(A& a){

}

void TestRefAndValue(){
    A a;
    //以值作为函数参数
    size_t begin1 = clock();
    for(size_t i = 0;i < 10000; ++i)
        TestFunc1(a);
    size_t end1 = clock();

    //以引用作为函数参数
    size_t begin2 = clock();
    for(size_t i = 0;i < 10000;++i)
        TestFunc2(a);
    size_t end2 = clock();

    //分别计算两个函数运行结束后的时间
    cout<<"TestFunc1(int*)-time:"<<end1-begin1<<endl;
    cout<<"TestFunc2(int&)-time:"<<end2-begin2<<endl;
}
//运行多次，检测值和引用在传参方面的效率区别
int main(){
    for(int i =0;i < 10;++i){
        TestRefAndValue();
    }
    return 0;
}
