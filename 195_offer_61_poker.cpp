//
// Created by Zeno on 2020/3/8.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return false;
        }

        int countZero = 0;
        int diff = 0;
        for(auto& num : nums)
        {
            if(num == 'A')
            {
                num = 1;
            }
            else if(num == 'J')
            {
                num = 11;
            }
            else if(num == 'Q')
            {
                num = 12;
            }
            else if(num == 'K')
            {
                num = 13;
            }
            else if(num == 0)
            {
                countZero++;
            }
        }

        sort(nums.begin(), nums.end());

        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                continue;
            }

            if(nums[i - 1] == 0)
            {
                continue;
            }

            if(nums[i] == nums[i - 1])
            {
                return false;
            }

            diff += nums[i] - nums[i - 1];
        }

        if((diff - ((int)nums.size() - 1)) <= countZero)
            return true;

        return false;
    }
};

int main()
{
    Solution s;
    vector<int> v({11,0,9,0,0});
    cout << s.isStraight(v);
    return 0;
}