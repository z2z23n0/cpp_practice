//
// Created by Zeno on 2020/1/29.
//

class Solution {
public:
    bool g_InvaildInput = false;
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size() == 0)
        {
            g_InvaildInput = true;
            return 0;
        }

        int CurSum = 0;
        int GreatestSum = 0x80000000;

        for(auto& num : array)
        {
            if(CurSum <= 0)
            {
                CurSum = num;
            }
            else
            {
                CurSum += num;
            }
            if(CurSum >= GreatestSum)
            {
                GreatestSum = CurSum;
            }
        }

        return GreatestSum;
    }
};