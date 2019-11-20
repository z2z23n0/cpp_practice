//
// Created by Zeno on 2019/11/20.
//

#include <iostream>
using namespace std;

template <class T>
class smart_ptr{
    T* m_ptr;
public:
    smart_ptr(T* ptr = nullptr) :
        m_ptr(ptr)
    {

    }
    ~smart_ptr(){
        if(m_ptr){
            delete [] m_ptr;
            m_ptr = nullptr;
        }
    }
    T&operator*(){
        return *m_ptr;
    }
    T*operator->(){
        return m_ptr;
    }
    T&operator[](int i){
        return m_ptr[i];
    }
};
int main(){

    return 0;
}
