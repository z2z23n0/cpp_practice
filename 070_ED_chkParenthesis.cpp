//
// Created by Zeno on 2019/11/17.
//
#include <stack>
#include <string>
using namespace std;

bool chkParenthesis(string A,int n) {
    stack<char> sc;
    for(auto ele:A){
        switch (ele){
            case '(':
                sc.push(ele);
                break;
            case ')':
            {
                if(sc.empty() || sc.top()!='(')
                    return false;
                else
                    sc.pop();
            }
                break;
            default:
                return false;
        }
    }
    return true;
}
