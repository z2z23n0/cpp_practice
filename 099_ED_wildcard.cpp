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
        //'*'的匹配
        if(*si1 == '*'){
            if(si1+1 == str1.end()){
                return true;
            }
            while(si2!=str2.end()){
                if(*si2 == '?'){
                    si1++;
                    si2++;
                }
                //当'*'匹配到不是“字符”时，返回false
                if(!(((*si2>='a')&&(*si2<='z'))||
                     ((*si2>='A')&&(*si2<='Z'))||
                     ((*si2>='0')&&(*si2<='9'))
                        )||(*si2 == '?')){
                    return false;
                }
                si2++;
                //当str1中'*'的下一个与str2相同时视为匹配完成
                if(*si2 == *(si1+1)){
                    si1++;
                    break;
                }
            }
            if(si2 == str2.end()){
                return false;
            }
            si2++;
            continue;
        }
        //'?'的匹配
        if(*si1 == '?'){
            //当'?'匹配到不是“字符”时，返回false
            if(!(((*si2>='a')&&(*si2<='z'))||
                 ((*si2>='A')&&(*si2<='Z'))||
                 ((*si2>='0')&&(*si2<='9')))){
                return false;
            }
            si2++;
            continue;
        }
        if(*si1 != *si2){
            return false;
        }
    }
    return true;
}
int main(){
    string str1,str2;
    while(cin>>str1>>str2){
        cout<<boolalpha<<judgment(str1,str2)<<endl;
    }
    return 0;
}
