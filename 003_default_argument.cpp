//
// Created by Zeno on 2019/10/27.
//

#include <iostream>
using namespace std;
void TestFunc(int a = 0){
    cout<<a<<endl;
}
void TestFunc1(int a = 10,int b = 20,int c = 30){
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"c = "<<c<<endl;
}
void TestFunc2(int a,int b,int c); //缺省参数不能在函数声明和定义中同时出现，即使缺省参数的值在声明和定义中都一样，如果要写声明，只能在函数声明中不缺省
void TestFunc2(int a,int b = 10,int c = 20){
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"c = "<<c<<endl;
}
int main(){
    //TestFunc(); //没有传参时，使用参数的默认值
    //TestFunc(10); //传参时，使用制定的实参
    //TestFunc1();
    TestFunc2(1,1);
}

