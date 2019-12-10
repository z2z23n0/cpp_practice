//
// Created by Zeno on 2019/12/10.
//
#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

//测试用例：
//s为空，dict为空
//s = "leetcode",dict = "leet","code"
//s = "leetcode",dict = "let","code"
//s = "leetcode",dict = "leet","codk"

class Solution{
public:
    bool wordBreak(string s, unordered_set<string> &dict){
        if(s.empty()){
            return false;
        }
        if(dict.empty()){
            return false;
        }
        int len = s.size();
        vector<bool> canBreak(len+1,false);
        canBreak[0] = true;
        for(int i = 1;i <= len;++i){
            for(int j = i - 1;j >= 0; --j){
                if(canBreak[j]){
                    if(dict.find(s.substr(j,i - j)) != dict.end()){
                        canBreak[i] = true;
                        break;
                    }
                }
            }
        }
        return canBreak[len];
    }
};
