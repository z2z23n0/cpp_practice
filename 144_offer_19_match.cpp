//
// Created by Zeno on 2020/1/17.
//

#include <iostream>
using namespace std;

class Solution {
public:
    /*
    测试用例：
    1. str为空，pattern为空
    */
    bool match(char* str, char* pattern)
    {
        if(str == nullptr && pattern == nullptr)
        {
            return true;
        }
        if(str == nullptr || pattern == nullptr)
        {
            return false;
        }

        char* ps = str;
        char* pp = pattern;

        if(*ps == '\0' && *pp == '\0')
        {
            return true;
        }
        if(*ps != '\0' && *pp == '\0')
        {
            return false;
        }

        while((*ps != '\0') && (*pp != '\0'))
        {
            if(*ps == *pp)
            {
                ps++;
                pp++;
            }
            else
            {
                if(*pp == '.' && (*(pp+1) != '*'))
                {
                    ps++;
                    pp++;
                }
                else
                {
                    if(*(pp+1) == '*')
                    {
                        pp += 2;
                        ps++;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        if(*ps == '\0' && *pp == '\0')
        {
            return true;
        }
        if(*ps == '\0' && (*(pp+1) == '*'))
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution sl;
    cout<<sl.match("a",".*")<<endl;
    return 0;
}