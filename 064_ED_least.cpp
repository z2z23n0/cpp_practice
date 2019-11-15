//
// Created by Zeno on 2019/11/15.
//
#include <iostream>
using namespace std;

int gcd(int a,int b){
    while(a!=b){
        if(a>b)
            a=a-b;
        else
            b=b-a;
    }
    return a;
}
int main(){
    int a,b;
    cin>>a;
    cin>>b;
    int least;
    least = a/gcd(a,b)*b;
    cout<<least<<endl;
    return 0;
}
