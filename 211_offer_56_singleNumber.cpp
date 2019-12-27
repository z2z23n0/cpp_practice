//
// Created by Zeno on 2020/3/15.
//
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> mp;
        for(auto num : nums)
        {
            mp[num]++;
        }

        for(auto m : mp)
        {
            if(m.first == 1)
                return m.second;
        }

        return 0;
    }
};

