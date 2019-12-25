//
// Created by Zeno on 2019/12/25.
//
#include <iostream>
#include <vector>
using namespace std;

//测试用例：数组长度为0
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 0){
            return 0;
        }
        vector<int>::iterator it;
        for(it=rotateArray.begin();it!=rotateArray.end();it++){
            if(*it > *(it+1)){
                return *(it+1);
            }
        }
    }
};