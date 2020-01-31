//
// Created by Zeno on 2020/2/2.
//

#include <iostream>
using namespace std;

int longestSubstringWithoutDuplication(const std::string& str)
{
    int curLength = 0;
    int maxLength = 0;

    int* position = new int[26];
    for(int i = 0; i < 26; ++i)
    {
        position[i] = -1;
    }

    for(int i = 0; i < str.size(); ++i)
    {
        int prevIndex = position[str[i] - 'a'];

        if(prevIndex < 0 || i - prevIndex > curLength)
        {
            ++curLength;
        }
        else
        {
            if(curLength > maxLength)
            {
                maxLength = curLength;
            }

            curLength = i - prevIndex;
        }
        position[str[i] - 'a'] = i;
    }

    if(curLength > maxLength)
    {
        maxLength = curLength;
    }

    delete[] position;
    return maxLength;
}

int main()
{
    cout<<longestSubstringWithoutDuplication("!@#*()$!")<<endl;
    return 0;
}
