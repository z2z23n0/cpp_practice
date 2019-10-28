//
// Created by Zeno on 2019/11/3.
//
#include <iostream>
using namespace std;
class TestSt{
public:
    static int m_s_i;
    int a;
    TestSt(){
        m_s_i++;
    }
    static void testst(){
        m_s_i = 4;
    }
};
int TestSt::m_s_i = 0;
int main(){
    TestSt t1;
    TestSt t2;
    TestSt t3;
    TestSt::testst();
    cout<<TestSt::m_s_i<<endl;
    return 0;
}

