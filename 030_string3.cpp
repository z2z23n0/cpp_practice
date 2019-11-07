//
// Created by Zeno on 2019/11/7.
//

#include <string>
#include <iostream>
using namespace std;
int main(){
    string s1;
    s1.append("abc");
    s1+="def";
    s1.append("ghi");
    cout<<s1;
    return 0;
}
