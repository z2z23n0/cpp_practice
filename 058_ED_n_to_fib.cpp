//
// Created by Zeno on 2019/11/13.
//

#include <iostream>
#include <vector>
using namespace std;
int Fib(int n){
    if(n == 0)
        return 0;
    if(n == 1||n ==2)
        return 1;
    return Fib(n-1)+Fib(n-2);
}
int main(){
    vector<int> a;
    for(int i = 0;i<40;i++){
        a.push_back(Fib(i));
    }
    vector<int>::iterator fi;
    int n;
    cin>>n;
    int sub = n - a[0];
    for(fi = a.begin()+1;fi!=a.end();fi++){
        if(sub >= ((n-*fi>0)?(n-*fi):(-(n-*fi)))) {
            sub = n - *fi;
            continue;
        }else{
            if(sub<0)
                sub = -sub;
            cout<<sub;
            break;
        }
    }
    return 0;
}
