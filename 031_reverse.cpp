//
// Created by Zeno on 2019/11/8.
//

#include <iostream>
#include <string>
using namespace std;

void reverseString(string& s){
   int i ,j;
   for(i = 0,j = s.size()-1;i<j;i++,j--){
       swap(s[i],s[j]);
   }
}
int main(){
    string s1("ikun");
    reverseString(s1);
    cout<<s1;
    return 0;
}
