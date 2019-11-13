//
// Created by Zeno on 2019/11/13.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s,table = "0123456789ABCDEF";
    int m,n;
    cin>>m>>n;
    bool flag = false;

    if(m<0){
        m = -m;
        flag = true;
    }
    while(m){
        s+=table[m%n];
        m/=n;
    }
    if(flag)
        s+='-';
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    return 0;
}
