//
// Created by Zeno on 2019/11/12.
//

#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> v;
    //vector<int> v2(v.begin()+3,v.end()-2);
    int i;
    for(i = 1;i <=10;i++){
        v.push_back(i);
        cout<<v.capacity()<<endl;
    }
    vector<int>::iterator fi;
    vector<int>::reverse_iterator ri;
    //for(fi = v.begin();fi!=v.end();fi++){
    //    cout<<*fi<<' ';
    //}
    //for(ri = v.rbegin();ri!=v.rend();ri++){
    //    cout<<*ri<<' ';
    //}
    return 0;
}
