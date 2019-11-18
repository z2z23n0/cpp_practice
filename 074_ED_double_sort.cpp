//
// Created by Zeno on 2019/11/18.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string> v;
    v.resize(n);
    for(auto& str : v)
        cin>>str;
    bool len = true,ascii = true;
    for(size_t i = 1;i < v.size();i++){
        if(v[i-1].size() >= v[i].size()){
            len = false;
            break;
        }
    }
    for(size_t i = 1;i<v.size();i++){
        if(v[i-1] >= v[i]){
            ascii = false;
            break;
        }
    }
    if(len&&ascii)
        cout<<"both";
    else if(len&&!ascii)
        cout<<"lengths";
    else if(!len&&ascii)
        cout<<"lexicographically";
    else if(!len&&!ascii)
        cout<<"none";
    return 0;
}

