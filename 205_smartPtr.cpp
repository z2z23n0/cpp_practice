//
// Created by Zeno on 2020/3/14.
//

#include <iostream>
#include <memory>

using namespace std;

// 对资源进行引用计数的类
template <typename T>
class RefCount
{

};
template<typename T>
class CSmartPtr
{
public:
    CSmartPtr(T *ptr = nullptr)
            : mptr(ptr)
    {

    }

    ~CSmartPtr()
    {
        delete mptr;
    }

    T& operator*()
    {
        return *mptr;
    }

    T* operator->()
    {
        return mptr;
    }
private:
    T *mptr;
};
