//
// Created by Zeno on 2020/2/10.
//

class Solution {
public:
    int binarySearch(vector<int>& data, double num)
    {
        int start = 0, end = data.size() - 1;
        while(start <= end)
        {
            int middle = (end - start) / 2 + start;
            if(data[middle] < num)
            {
                start = middle + 1;
            }
            else if(data[middle] > num)
            {
                end = middle - 1;
            }
        }
        return start;

    }
    int GetNumberOfK(vector<int> data ,int k) {
        return binarySearch(data, k + 0.5) - binarySearch(data, k - 0.5);
    }
};