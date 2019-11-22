//
// Created by Zeno on 2019/11/23.
//

#include <iostream>
using namespace std;

int count_1(int num){
    int count = 0;
    while(num){
        if(num&1 == 1)
            count++;
        num = num>>1;
    }
    return count;
}
int main(){
    int num;
    while(cin>>num){
        cout<<count_1(num)<<endl;
    }
    return 0;
}
