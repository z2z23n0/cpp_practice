//
// Created by Zeno on 2019/11/22.
//
#include <iostream>
using namespace std;

int getLCA(int a,int b){
    while (a!=b){
        if(a>b)
            a/=2;
        else
            b/=2;
    }
    return a;
}
int main(){
    return 0;
}

