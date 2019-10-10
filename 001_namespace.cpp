//
// Created by Zeno on 2019/10/27.
//
//namespace N1{
//    int a;
//    int Add(int left,int right){
//        return left + right;
//    }
//}
//
//namespace N2{
//    int a;
//    int b;
//    int Add(int left,int right){
//        return left + right;
//    }
//    namespace N3{
//        int c;
//        int d;
//        int Sub(int left,int right){
//            return left - right;
//        }
//    }
//}
#include <iostream>
namespace N{
    int a = 10;
    int b = 20;
    int Add(int left,int right){
        return left + right;
    }
    int Sub(int left,int right){
        return left - right;
    }
}
//using N::b;      -->使用using将命名空间中成员引入
using namespace N;
int main(){
    //printf("%d\n",a);    -->编译出错，无法识别a
    //printf("%d\n",N::a);        N->命名空间名称     :: ->作用域限定符
    //printf("%d\n",b);
    Add(10,20);
    return 0;
}
