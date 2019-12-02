//
// Created by Zeno on 2019/12/1.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef pair<char,int> ciPair;
typedef vector<ciPair> vector_type;

int main(){
    string str;
    while(cin>>str){
        vector_type v;
        for(auto&i : str){
            int flag = 0;
            vector_type::iterator iter;
            for(iter = v.begin();iter!=v.end();iter++){
                if (iter->first == i){
                    flag = 1;
                }
            }
            if(flag == 0) {
                v.push_back(ciPair(i, 1));
            }
        }
        vector_type::iterator iter;
        for(iter = v.begin();iter!=v.end();iter++){
            cout<<iter->first;
        }
        cout<<endl;
    }

    return 0;
}
