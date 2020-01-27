//
// Created by Zeno on 2020/1/28.
//

class Solution {
private:
    vector<string> v;
public:
    void Permutation(string& str, string::iterator it_begin)
    {
        if(*it_begin == '\0')
        {
            v.push_back(str);
        }
        else
        {
            for(string::iterator it = it_begin; *it != '\0'; ++it)
            {
                char temp = *it;
                *it = *it_begin;
                *it_begin = temp;

                Permutation(str, it_begin + 1);

                temp = *it;
                *it = *it_begin;
                *it_begin = temp;
            }
        }
    }
    vector<string> Permutation(string str) {
        if(str.size() == 0)
        {
            return v;
        }

        Permutation(str, str.begin());

        return v;
    }
};