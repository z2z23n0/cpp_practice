//
// Created by Zeno on 2019/11/26.
//

#include <iostream>
#include <string>
using namespace std;

bool judgment(string str1,string str2){
    string::iterator si1;
    string::iterator si2 = str2.begin();
    for(si1=str1.begin();si1!=str1.end();si1++){
        if(*si1 == *si2){
            si2++;
            continue;
        }
        if(*si1 == '*'){
            while(si2!=str2.end()){
                if(!(((*si2>='a')&&(*si2<='z'))||
                        ((*si2>='A')&&(*si2<='Z'))||
                        ((*si2>='0')&&(*si2<='9')))){
                    return false;
                }
            }
        }
    }
}
int main(){
    string str1,str2;
    while(cin>>str1>>str2){
        cout<<judgment(str1,str2)<<endl;
    }
    return 0;
}
