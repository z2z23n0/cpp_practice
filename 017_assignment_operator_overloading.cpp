//
// Created by Zeno on 2019/11/3.
//
#include <iostream>
using namespace std;
class TestOp{
public:
    int m_a;
    int m_b;
    TestOp() :
    m_a(0),
    m_b(0)
    {

    }
    TestOp(int a,int b) :
    m_a(a),
    m_b(b)
    {

    }
    void changedata(int a,int b){
        m_a = a;
        m_b = b;
    }
    TestOp operator + (const TestOp& s) const { //这里的后一个const是用来修饰this的
        TestOp res;
        res.m_a = m_a + s.m_a;  //等号后面的第一个m_a是this的成员
        res.m_b = m_b + s.m_b;
        return res;
    }
    TestOp& operator = (const TestOp& s){
        m_a = s.m_a;
        m_b = s.m_b;

        return *this;
    }
};
int main(){
    TestOp a(3,5);
    TestOp b(2,7);

    TestOp c;
    const TestOp d;
    c = c = a + b;

    d.changedata(2,3);
    cout<<c.m_a<<' '<<c.m_b<<endl;
    return 0;
}
