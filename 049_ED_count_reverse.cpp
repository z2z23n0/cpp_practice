//
// Created by Zeno on 2019/11/12.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isReverse(string s){
    if(s.size() == 0){
        return false;
    }
    string tmp = s;
    reverse(tmp.begin(),tmp.end());
    return s == tmp;
}
int countReverse(string a,string b){
    int count = 0;
    for(int i = 0;i < a.size();++i){
        string tmp = a;
        tmp.insert(i,b);
        if(isReverse(tmp))
            count++;
    }
    return count;
}
int main(){
    string a,b;
    cin>>a;
    cin>>b;
    if(a.size() == 0){
        cout<<(isReverse(b)?1:0)<<endl;
    }else if(b.size() == 0){
        cout<<(isReverse(a)?(a.size()):0);
    }else {
        cout << countReverse(a, b) << endl;
    }
    return 0;
}
