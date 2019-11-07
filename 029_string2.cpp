//
// Created by Zeno on 2019/11/7.
//

#include <string>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <typeinfo>
using namespace std;

int main(){
    string s1("Hello");
    cout<< typeid(s1).name()<<endl;
    cout<< typeid(s1.c_str()).name()<<endl;
    for(size_t i = 0;i < s1.size();i++){
        cout<<s1[i];
    }
    cout<<endl;
    for(auto i = s1.begin();i != s1.end();i++){
        cout<<*i;
    }
    cout<<endl;
    for(auto& i: s1){
        cout<<i;
    }
    cout<<s1<<endl;
    return 0;
}
