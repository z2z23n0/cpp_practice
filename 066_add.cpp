//
// Created by Zeno on 2019/11/16.
//

#include <iostream>
using namespace std;

int addAB(int A,int B){
    if(B == 0)
        return A;
    int sum = A^B;
    int carry = (A&B)<<1;
    return addAB(sum,carry);
}
int main(){
    int a,b;
    cin>>a;
    cin>>b;
    cout<<addAB(a,b);
    return 0;
}
