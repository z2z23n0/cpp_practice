//
// Created by Zeno on 2019/10/27.
//

#include <iostream>
using namespace std;
//void TestRef(){
//    int a = 10;
//    int& ra = a; //->定义引用类型
//    printf("%p\n",&a);
//    printf("%p\n",&ra);
//}
void TestRef(){
    int a = 10;
    //int& ra;
    int& ra = a;
    int& rra = a;
    printf("%p %p %p\n",&a,&ra,&rra);
}
void TestConstRef(){
    const int a = 10;
    //int& ra = a;  //该语句编译时会出错，a为常量
    const int& ra = a;
    //int& b = 10; //该语句编译时会出错，b为常量
    const int& b = 10;
    double d = 12.34;
    //int& rd = d; //该语句编译时会出错，类型不同
    const int& rd = d;
    cout<<rd<<endl;
}
void Swap(int& left,int& right){
    int temp = left;
    left = right;
    right = temp;
}
int& TestRefReturn(int& a){
    a += 10;
    return a;
}
int& Add(int a,int b){
    int c = a + b; //这里的c在函数生命周期结束时就销毁了，不能用栈上的空间作为引用类型返回
    return c;
}
int main(){
    //TestRef();
    //TestConstRef();
    int& ret = Add(1,2);
    Add(3,4);
    cout << "Add(1,2) is :"<< ret << endl;
    return 0;
}
