//
// Created by Zeno on 2019/11/11.
//

#include <iostream>
#include <string>
using namespace std;
int main(){
    string str,res,cur;
    cin>>str;
    for(int i = 0;i <= str.size();++i){
        if(str[i] >= '0' && str[i] <= '9'){
            cur+=str[i];
        }else{
            if(res.size() < cur.size()){
                res = cur;
            } else{
                cur.clear();
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
