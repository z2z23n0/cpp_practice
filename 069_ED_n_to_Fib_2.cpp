//
// Created by Zeno on 2019/11/17.
//

#include <iostream>
using namespace std;

int main(){
    int N,f,l = 0,r = 0,f0 = 0,f1 = 1;
    cin>>N;
    while (1){
        f = f0+f1;
        f0 = f1;
        f1 = f;
        if(f < N)
            l = N-f;
        else{
            r = f - N;
            break;
        }
    }
    cout<<min(l,r)<<endl;
    return 0;
}
