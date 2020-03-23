//
// Created by Zeno on 2020/3/21.
//

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int head = 0, rear = nums.size() - 1;
        while(head < rear)
        {
            if(nums[head] + nums[rear] == target)
            {
                res.push_back(nums[head]);
                res.push_back(nums[rear]);
                return res;
            }
            else if(nums[head] + nums[rear] < target)
            {
                head++;
            }
            else
            {
                rear--;
            }
        }

        return res;
    }
};