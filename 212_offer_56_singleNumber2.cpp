//
// Created by Zeno on 2020/3/15.
//

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> bit_map;

        for(int i = 0; i < nums.size(); i++)
        {
            long digit = 1;
            for(int j = 31; j >= 0; --j)
            {
                if(nums[i] & digit)
                    bit_map[j]++;
                digit = digit << 1;
            }
        }

        int ret = 0;
        for(int i = 0; i < 32; ++i)
        {
            ret = ret << 1;
            ret += bit_map[i] % 3;
        }
        return ret;
    }
};