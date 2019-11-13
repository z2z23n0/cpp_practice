//
// Created by Zeno on 2019/11/13.
//

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int StrToInt(string str){
    char arr[10000];
    memset(arr,0,10000);
    string::reverse_iterator i;
    int j = 0;
    int sign = 1;
    for(i = str.rbegin();i!=str.rend();i++){
        if(*i == '+') {
            sign *= 1;
        }
        else if(*i == '-'){
            sign*= -1;
        }
        else if(*i<'0'||*i>'9')
            return 0;
        else{
            arr[j] = *i - '0';
            j++;
        }
    }
    int digits = 1;
    int res = 0;
    for(auto& k : arr){
        res+= k*digits;
        digits*=10;
    }
    return res*sign;
}
int main(){
    string s = "-123456789";
    cout<<StrToInt(s)<<endl;
    return 0;
}
