//
// Created by Zeno on 2019/11/9.
//

#include <iostream>
#include <string>
using namespace std;

int main(){
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2);

    //使用哈希映射思想先统计str2字符出现次数
    int hashtable[256] = {0};
    for(size_t i= 0;i < str2.size();++i){
        hashtable[str2[i]]++;
    }
    string ret;
    for(size_t i = 0;i < str1.size();++i){
        if(hashtable[str1[i]] == 0){
            ret+=str1[i];
        }
    }
    cout<<ret<<endl;
    return 0;
}
