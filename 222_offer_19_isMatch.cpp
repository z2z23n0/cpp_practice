//
// Created by Zeno on 2020/3/23.
//

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty())
            return s.empty();

        if(p[1] == '*')
            return isMatch(s, p.substr(2)) || ((!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p)));
        else
            return !s.empty() && ((p[0] == s[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1)));
    }
};