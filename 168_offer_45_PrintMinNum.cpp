//
// Created by Zeno on 2020/1/30.
//

class Solution {
public:
    static bool cmp(int a, int b)
    {
        string A = "";
        string B = "";

        A += to_string(a);
        A += to_string(b);
        B += to_string(b);
        B += to_string(a);

        return A < B;
    }
    string PrintMinNumber(vector<int> numbers) {
        string ret = "";
        sort(numbers.begin(), numbers.end(), cmp);

        for(auto num : numbers)
        {
            ret += to_string(num);
        }

        return ret;
    }
};