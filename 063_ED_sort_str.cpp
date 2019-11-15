//
// Created by Zeno on 2019/11/14.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//string& sortByDic(string& s){
//
//}
int cmpByDic(string a,string b){
    return a.compare(b)<0;
}
int main(){
    int n;
    cin>>n;
    string str[n][100];
    for(int i = 0;i < n;i++){
        cin>>str[i];
    }
    sort(str,str+3,cmpByDic);
    cout<<a<<endl;
    return 0;
}
