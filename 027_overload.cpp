//
// Created by Zeno on 2019/11/7.
//


#include <iostream>
using namespace std;

class Test{
    int m_a;
public:
    Test(int a = 0):
        m_a(a)
    {

    }
    Test operator++(){
        m_a++;
        return *this;
    }
    Test operator++(int){
        Test tmp = *this;
        m_a++;
        return tmp;
    }
    friend ostream& operator <<(ostream& os,Test& t);
};
ostream& operator<<(ostream& os,Test& t){
    os<<t.m_a<<endl;
    return os;
}
int main(){
    Test t(7);
    Test t2 = ++t;
    cout << t <<endl;
    return 0;
}
