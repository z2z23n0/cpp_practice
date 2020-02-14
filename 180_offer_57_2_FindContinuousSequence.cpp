//
// Created by Zeno on 2020/2/14.
//

class Solution {
public:
    vector<vector<int>> ret;
    void push_ret(int start, int end)
    {
        vector<int> v;
        for(int i = start; i <= end; i++)
        {
            v.push_back(i);
        }
        ret.push_back(v);
        return;
    }
    vector<vector<int> > FindContinuousSequence(int sum) {
        if(sum < 3)
            return ret;
        int start = 1;
        int end = 2;
        int middle = (sum + 1) / 2;
        int curSum = start + end;

        while(start < middle)
        {
            if(curSum == sum)
                push_ret(start, end);

            while(curSum > sum && start < middle)
            {
                curSum -= start;
                start++;
                if(curSum == sum)
                    push_ret(start, end);
            }

            end++;
            curSum += end;
        }

        return ret;
    }
};