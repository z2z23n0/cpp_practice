//
// Created by Zeno on 2020/1/22.
//

#include <iostream>
#include <stack>
#include <assert.h>

using namespace std;

template <typename T> class StackWithMin
{
private:
    stack<T> m_data;
    stack<T> m_min;
public:
    void push(const T& value);
    void pop();
    const T& min() const;
};

template <typename T> void StackWithMin<T>::push(const T& value)
{
    m_data.push(value);

    if(m_min.size() == 0 || value < m_min.top())
        m_min.push(value);
    else
        m_min.push(m_min.top());
}

template <typename T> void StackWithMin<T>::pop()
{
    assert(!m_data.empty() && !m_min.empty());

    m_data.pop();
    m_min.pop();
}
template <typename T> const T& StackWithMin<T>::min() const
{
    assert(!m_data.empty() && !m_min.empty());

    return m_min.top();
}
