//
// Created by Zeno on 2019/11/21.
//

#include <iostream>
#include <map>
using namespace std;

int main(){
    pair<int,int> p;
    map<int,int> m;
    m.insert(pair<int,int>(1,9));
    m.insert(pair<int,int>(2,6));
    for(auto& i : m){
        cout<<i.first<<' '<<i.second<<endl;
    }
    return 0;
}
