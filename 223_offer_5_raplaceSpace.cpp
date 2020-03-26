//
// Created by Zeno on 2020/3/25.
//

class Solution {
public:
    string replaceSpace(string s) {
        if(s.empty())
            return s;

        string res;
        for(auto ch : s)
        {
            if(ch != ' ')
            {
                res += ch;
            }
            else
            {
                res += "%20";
            }
        }
        return res;
    }
};