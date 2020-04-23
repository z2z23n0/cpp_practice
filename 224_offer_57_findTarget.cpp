//
// Created by Zeno on 2020/3/26.
//
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> findContinuousSequence(int target) {
    vector<vector<int>> res;
    int half =(target + 1) / 2;
    int start = 1;
    int end = 2;
    int curSum = start + end;
    while(start < half && start < end)
    {
        if(curSum == target)
        {
            vector<int> temp;
            for(int i = start; i <= end; i++)
            {
                temp.push_back(i);
            }
            res.push_back(temp);
            end++;
            curSum += end;
        }
        else if(curSum > target)
        {
            curSum -= start;
            start++;
        }
        else
        {
            end++;
            curSum += end;
        }
    }
    return res;
}