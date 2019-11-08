//
// Created by Zeno on 2019/11/8.
//

#include <iostream>
#include <string>
using namespace std;
bool isLetter(char ch){
    return (ch >= 'a'&& ch <= 'z')||
            (ch >= 'A'&& ch<='Z');
}
string reverse(string source){
    int size = source.size();
    int index = 0;
    string destination;
    for(int i = 0; i < size;++i){
        if(isLetter(source[i])){
            index+=1;
        }
    }
}
int main(){

    return 0;
}
