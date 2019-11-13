//
// Created by Zeno on 2019/11/13.
//
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    for(int i = 1;i <= 10;i++){
        v.push_back(i);
    }
#if 0 //insert 1
    v.insert(v.begin()+5,20);
#elif 0
    v.insert(v.begin()+5,3,20);
#else
    int a[5] = {10,20,30,40,50};
    v.insert(v.begin()+5,a + 1,a +3);
#endif

#if 0 //erase
    v.erase(v.begin()+5);
#else
    v.erase(v.begin() + 5,v.end() - 3);
#endif
    for(auto& i : v){
        cout<<i<<' ';
    }
    return 0;
}

