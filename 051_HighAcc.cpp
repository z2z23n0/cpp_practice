//
// Created by Zeno on 2019/11/12.
//

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define NUMSIZE 10000

class HighAcc{
    char m_data[NUMSIZE];
    size_t m_size;
public:
    HighAcc(string s) :
        m_size(s.size())
    {
        memset(m_data,0,NUMSIZE);
        string::reverse_iterator i;
        int j = 0;
        for(i = s.rbegin();i != s.rend();i++){
            m_data[j] = *i - '0';
            j++;
        }
    }
    HighAcc():
        m_size(1)
    {
        memset(m_data,0,NUMSIZE);
    }
    HighAcc operator + (const HighAcc& s)const{
        HighAcc res;
        size_t maxsize = m_size > s.m_size?m_size:s.m_size;
        int i;
        int tmp;
        for(i = 0;i < maxsize;i++){
            tmp = m_data[i] + s.m_data[i] + res.m_data[i];
            res.m_data[i] = tmp%10;
            res.m_data[i+1] = tmp/10;
        }
        res.m_size = maxsize + res.m_data[i];
        return res;
    }
    operator string(){
        string s;
        int i;
        for(i = m_size - 1;i >= 0;i--){
            s.push_back(m_data[i] + '0');
        }
        return s;
    }
};
int main(){
    string s1("12345");
    string s2("98765");
    HighAcc num1(s1);
    HighAcc num2(s2);
    cout<<(string)(num1+num2);
    return 0;
}
