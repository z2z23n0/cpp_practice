//
// Created by Zeno on 2019/10/27.
//

#include <iostream>
#include <typeinfo>
//#include <exception>
using namespace std;
int TestAuto(){
    return 10;
}
int main(){
    int a =10;
    auto b = a;
    auto c = 'a';
    auto d = TestAuto();

    cout << typeid(b).name << endl;
}
