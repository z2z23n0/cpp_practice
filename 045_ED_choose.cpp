//
// Created by Zeno on 2019/11/11.
//

#include <iostream>
using namespace std;
int func(){
    int i,j,k = 0;
    for(i = 0,j = -1;0;i++,j++){
        k++;
    }
    return k;
}
int main(){
    cout<<(func());
    return 0;
}
