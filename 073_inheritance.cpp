//
// Created by Zeno on 2019/11/18.
//

#include <iostream>
using namespace std;

class TestBase{
public:
    int m_a;
    TestBase(int i) : m_a(i)
    {

    }
    void func(){
        cout<<"i am father"<<endl;
    }
};
class Test : public TestBase{
public:
    int m_a;
    Test(int a,int b) :
        TestBase(a),
        m_a(b)
    {

    }
    void func(){
        cout<<"i am son"<<endl;
    }
};
int main(){
    Test* pt = new Test(5,6);
    TestBase* ptb = pt;
    cout<<ptb->m_a;
    return 0;
}
