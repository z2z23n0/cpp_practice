//
// Created by Zeno on 2019/11/16.
//

#include <iostream>
using namespace std;

int chess(int m,int n){
    if(m == 1||n == 1)
        return m+n;
    return chess(m-1,n)+chess(m,n-1);
}
int main(){
    int m,n;
    cin>>m;
    cin>>n;
    cout<<chess(m,n);
    return 0;
}
