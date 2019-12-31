//
// Created by Zeno on 2020/3/16.
//
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string reverseWords(string s) {
    if(s.size() == 0)
        return s;

    reverse(s.begin(), s.end());
    string::iterator fast = s.begin();
    string::iterator slow = s.begin();

    while(slow != s.end())
    {
        while(fast != s.end() && (*fast) != ' ')
            fast++;
        reverse(slow, fast);
        if(fast != s.end())
            fast++;
        slow = fast;
    }


    fast = slow = s.begin();
    while(slow != s.end())
    {
        fast++;
        if(*fast == ' ' && *slow == ' ')
        {
            s.erase(slow);
        }
        slow = fast;
    }
    return s;
}

int main()
{
    cout << reverseWords("the sky is bulue") << endl;
    return 0;
}