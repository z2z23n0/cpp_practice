//
// Created by Zeno on 2020/2/20.
//

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.size() == 0)
            return str;

        int size = str.size();
        n %= str.size();
        str += str;
        return str.substr(n, size);
    }
};