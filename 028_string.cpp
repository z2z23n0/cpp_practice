//
// Created by Zeno on 2019/11/7.
//

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(){
    string s1;
    string s2("caixukun");
    string s3 = s2;
    string s4(5,'6');

    s1.push_back('1');
    s1.resize(10,'n');
    cout<<s1.size()<<endl;
    s1.push_back('2');
    for(auto& i : s1){
        cout<<i;
    }
    //cout<<s1<<endl;
    //for(auto& i : s1){
    //    printf("%d",i);
    //}
    //s4+=s3;
    //s4+="qiaobiluo";
    //s4.clear();
    //cout<<s1<<endl
    //    <<s2<<endl
    //    <<s3<<endl
    //    <<s4<<endl;
    return 0;
}
