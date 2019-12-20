//
// Created by Zeno on 2019/12/20.
//
#include <iostream>
#include <stack>
using namespace std;

//测试用例：
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int tmp;
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        tmp = stack2.top();
        stack2.pop();
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        cout<<tmp<<endl;
        return tmp;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(){
    Solution sl;
    sl.push(1);
    sl.push(2);
    sl.push(3);
    sl.pop();
    sl.pop();
    sl.push(4);
    sl.pop();
    sl.push(5);
    sl.pop();
    sl.pop();
    return 0;
}
