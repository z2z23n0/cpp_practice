//
// Created by Zeno on 2019/11/21.
//

#include <iostream>
#include <map>
#include <set>
#include <functional>
using namespace std;

int main(){
    int a[5] = {5,2,3,1,4};
    set<int> s(a,a+5);
    s.insert(6);
    for(auto & i : s){
        cout<<i<<' ';
    }
    return 0;
}
