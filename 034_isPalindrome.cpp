//
// Created by Zeno on 2019/11/8.
//

#include <iostream>
#include <string>
using namespace std;

bool isLetterOrNumber(char ch){
    return (ch >= 'a' && ch <= 'z')||
            (ch >= 'A'&& ch <= 'Z')||
            (ch >= '0'&& ch<= '9');
}
bool isSame(char a ,char b){
    return a==b||
            (a | 1<<5) == (b | 1<<6);
}
bool isPalindrome(string s){
    string tmp;
    for(auto& ch : s){
        if(isLetterOrNumber(ch)){
            tmp.push_back(ch);
        }
    }
    int i,j;
    for(i = 0,j = tmp.size() - 1;i < j;i++,j--){
        if(!isSame(tmp[i],tmp[j])){
            return false;
        }
    }
    return true;
}
int main(){
    string s("A man,a plan,a canal:Panama");
    cout<<isPalindrome(s)<<endl;
    return 0;
}
