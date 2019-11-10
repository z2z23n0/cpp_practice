//
// Created by Zeno on 2019/11/8.
//

#include <iostream>
#include <string>
using namespace std;

int firstUniqChar(string s){
    int count[26] = {0};
    for(auto& ch:s){
        count[ch - 'a']++;
    }
    //int j = 0;
    //for(auto& i : count){
    //    cout<<(char)(j++ + 'a')<<' '<<i<<endl;
    //}
    for(int i = 0; i < s.size();i++){
        if(count[s[i] - 'a'] == 1){
            return i;
        }
    }
    return -1;
}
int main(){
    string s;
    cin>>s;
    firstUniqChar(s);
    return 0;
}
