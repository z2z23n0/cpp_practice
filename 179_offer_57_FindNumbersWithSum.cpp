//
// Created by Zeno on 2020/2/13.
//

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> ret;
        int start = 0;
        int end = array.size() - 1;

        while(start < end)
        {
            int curSum = array[start] + array[end];
            if(curSum == sum)
            {
                ret.push_back(array[start]);
                ret.push_back(array[end]);
                break;
            }
            else if(curSum > sum)
            {
                end--;
            }
            else
            {
                start++;
            }
        }
        return ret;
    }
};