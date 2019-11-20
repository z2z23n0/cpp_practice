//
// Created by Zeno on 2019/11/19.
//

#include <iostream>
using namespace std;

int addAB(int A,int B){
    int sum = 0,carry = 0;
    while(B!=0){
        sum = A^B;
        carry = (A&B)<<1;
        A = sum;
        B = carry;
    }
    return sum;
}
int main(){
    int a = 5,b = 6;
    return 0;
}
