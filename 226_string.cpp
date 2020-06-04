//
// Created by Zeno on 2020/4/5.
//

#include <cstring>
#include <iostream>
using namespace std;
class String
{
public:
    String()
            : m_data(new char[1])
    {
        *m_data = '\0';
    }
    ~String()
    {
        delete[] m_data;
        m_data = nullptr;
    }
    String(const char *str)
            : m_data(new char[strlen(str) + 1])
    {
        strcpy(m_data, str);
    }
    String(const String &str)
    {
        String tmp(str.m_data);
        std::swap(m_data, tmp.m_data);
    }
    String &operator=(String str)
    {
        std::swap(m_data, str.m_data);
        return *this;
    }
    size_t size() const
    {
        return strlen(m_data);
    }
    const char *c_str() const
    {
        return m_data;
    }
private:
    char *m_data;
};
