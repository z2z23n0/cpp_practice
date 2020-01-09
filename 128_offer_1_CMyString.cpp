//
// Created by Zeno on 2020/1/9.
//

#include <iostream>
#include <cstring>
using namespace std;

class CMyString
{
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);

private:
    char* m_pData;

public:
    CMyString&operator =(const CMyString& str)//注意1：这里的返回值类型是该类的引用，这样可以进行连续赋值
                                            //注意2：这里传入的参数类型为常量引用，避免了传入实例会调用拷贝构造造成资源浪费，同时
                                            // const保证了不会对参数造成修改
    {
        if (this == &str)
        {
            return *this;
        }//注意3：先判断传入的参数和*this是否是同一个实例，如果是同一个则直接返回，否则下面的delete等操作会导致出错

        delete []m_pData;
        m_pData = nullptr;//注意4：需要在分配新内存之前释放自身已有的空间，否则将出现内存泄漏

        m_pData = new char[strlen(str.m_pData) + 1];
        strcpy(m_pData, str.m_pData);

        return *this;//注意5：返回值是该实例自身的引用
    }
};
