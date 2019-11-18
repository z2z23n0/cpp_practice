//
// Created by Zeno on 2019/11/17.
//

#include <iostream>
#include <vector>
using namespace std;

int count_1(int num){
    vector<int> arr;
    while(num){
        arr.push_back(num%2);
        num/=2;
    }
    int ret = 0;
    int count = 0;
    for(int i = arr.size()-1;i>=0;--i){
        if(arr[i] == 1) {
            count++;
            continue;
        }
        if(count > ret) {
            ret = count;
            count = 0;
        }
    }
    if(count > ret) {
        ret = count;
    }
    return ret;
}
int main(){
    int num;
    cin>>num;
    cout<<count_1(num)<<endl;
    return 0;
}
