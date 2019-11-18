//
// Created by Zeno on 2019/11/18.
//
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int binInsert(int n,int m,int j,int i){
    vector<int> bin_n;
    vector<int> bin_m;
    while(n){
        bin_n.push_back(n%2);
        n/=2;
    }
    while(m){
        bin_m.push_back(m%2);
        m/=2;
    }
    for(int k = 0;j <= i;j++,k++){
        bin_n[j] = bin_m[k];
    }
    int res = 0;
    for(int k = bin_n.size() - 1;k>=0;k--){
        if(bin_n[k]!=0){
            res+=pow(2,k);
        }
    }
    return res;
}
int main(){
    cout<<binInsert(356353,184,3,11);
    return 0;
}
