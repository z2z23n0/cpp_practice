//
// Created by Zeno on 2019/11/13.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool chkParenthesis(string A,int n){
    stack<int> st;
    for(auto& i : A){
        if(i == '('){
            st.push(1);
        }
        if(i == ')'){
            if(st.empty())
                return false;
            st.pop();
        }
    }
    if(st.empty())
        return true;
    else
        return false;
}
int main(){
    string A;
    size_t n;
    cin>>A;
    cin>>n;
    cout<<boolalpha<<chkParenthesis(A,n);
    return 0;
}
