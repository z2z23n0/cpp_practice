//
// Created by Zeno on 2019/11/11.
//

#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a;
    a.resize(n+1);
    a[n] = 0;
    int i = 0;
    for(i = 0;i<n;++i){
        cin>>a[i];
    }
    i = 0;
    int count = 0;
    while(i < n){
        if(a[i] < a[i+1]){
            //非递减子序列
            while (i < n && a[i] <= a[i+1])
                i++;
            count++;
            i++;
        } else if(a[i] == a[i+1]){
            i++;
        }else{
            //非递增子序列
            while (i < n && a[i] >= a[i+1])
                i++;
            count++;
            i++;
        }
    }
    cout<<count<<endl;
    return 0;
}
