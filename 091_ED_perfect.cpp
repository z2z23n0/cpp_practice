//
// Created by Zeno on 2019/11/23.
//

#include <iostream>
#include <vector>
using namespace std;

int count(int n){
    size_t count = 0;
    for(int i = 1;i <= n;i++){
        vector<int> v;
        int sum = 0;
        for(int j = 1;j < i;j++){
            if(i%j==0)
                v.push_back(j);
        }
        for(int j = 0;j < v.size();j++){
            sum+=v[j];
        }
        if(sum == i)
            count++;
    }
    return count;
}
int main(){
    int n;
    while(cin>>n){
        cout<<count(n)<<endl;
    }
    return 0;
}
