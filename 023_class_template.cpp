//
// Created by Zeno on 2019/11/6.
//
#include <iostream>
using namespace std;

template <class T>
class Test{
    T m_a;
public:
    Test(T s = 0) :
        m_a(s)
    {

    }
    void showData(){
        cout<<m_a<<endl;
    }
    void setData(T s);
};
template <class T>
void Test<T>::setData(T s){
    m_a = s;
}
int main(){
    Test<int> a(6);
    a.showData();
    return 0;
}

