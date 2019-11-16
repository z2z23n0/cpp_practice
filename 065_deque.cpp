//
// Created by Zeno on 2019/11/15.
//
#include <deque>
#include <iostream>
using namespace std;
int main(){
    deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_front(-1);
    deque<int>::iterator di = d.begin();
    cout<<di[2]<<endl;
    return 0;
}
