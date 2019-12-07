//
// Created by Zeno on 2019/12/7.
//

#include <iostream>
#include <vector>
using namespace std;

int getValue(vector<int> gifts, int n) {
    // write code here
    int value,count = 0;
    vector<int>::iterator iter = gifts.begin();
    for(;iter!=gifts.end();iter++){
        if(count == 0){
            value = *iter;
            count++;
        }else{
            if(*iter == value){
                count++;
            }else{
                count--;
            }
        }
    }
    if(value == *(iter-1) && count == 1)
        return 0;
    if(count > 0){
        return value;
    }
    return 0;
}
int main(){
    vector<int> vt;
    vt.push_back(1);
    vt.push_back(2);
    vt.push_back(3);
    vt.push_back(4);
    vt.push_back(5);
    cout<<getValue(vt,5)<<endl;
}
