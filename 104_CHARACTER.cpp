//
// Created by Zeno on 2019/12/1.
//

#include <iostream>
#include <map>
using namespace std;
struct DisableCompare : public std::binary_function<char, char, bool>
{
    bool operator()(char lhs, char rhs) const
    {
        return true;
    }
};

int main(){
    string str;
    while(cin>>str){
        map<char,int,DisableCompare> mapStr;
        for(auto& i : str){
            mapStr[i]++;
        }
        map<char,int>::iterator iter;
        for(iter = mapStr.begin();iter!=mapStr.end();iter++){
            cout<<iter->first;
        }
        cout<<endl;
    }
    return 0;
}
