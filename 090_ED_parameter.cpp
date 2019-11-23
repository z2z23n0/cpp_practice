//
// Created by Zeno on 2019/11/23.
//

#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    while(getline(cin,str)){
        int count = 0;
        for(int i = 0;i < str.size();i++){
            if(str[i] == ' '){
                count++;
            }
            if(str[i] == '"'){
                do{
                    i++;
                }while(str[i]!='"');
            }
        }
        cout<<count+1<<endl;
        int flag = 1;
        for(int i = 0;i < str.size();i++){
            if(str[i] == '"')
                flag^=1;
            if(str[i]!='"'&&str[i]!=' ')
                cout<<str[i];
            if(!flag && str[i] == ' ')
                cout<<str[i];
            if(flag && str[i] == ' ')
                cout<<endl;
        }
        return 0;
    }
    return 0;
}
