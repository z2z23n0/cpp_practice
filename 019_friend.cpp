//
// Created by Zeno on 2019/11/4.
//

#include <iostream>
#include <fstream>
using  namespace std;

class FTest{
    int m_a;
    int m_b;
public:
    FTest() :
    m_a(0),
    m_b(0)
    {

    }
    FTest(int a,int b):
        m_a(a),
        m_b(b)
    {

    }
    void setNum(int a,int b);

    friend ostream& operator<<(ostream& os,FTest& data);
    friend istream& operator>>(istream& is,FTest& data);
};
void FTest::setNum(int a,int b){
    m_a = a;
    m_b = b;
}
ostream& operator<<(ostream& os,FTest& data){
    os<<data.m_a<<' '<<data.m_b;
    return os;
}
istream& operator>>(istream& is,FTest& data){
    is >> data.m_a>>data.m_b;
    return is;
}
int main(){
    FTest ft;
    ofstream os("1.txt");
    cin >> ft;
    os<<ft<<endl;
    os.close();
    return 0;
}
