//
// Created by Zeno on 2020/2/12.
//

class Solution {
public:
    unsigned int FindFirstBitIs1(int num)
    {
        int indexBit = 0;
        while(((num & 1) == 0) && (indexBit < 8 * sizeof(int)))
        {
            num = num >> 1;
            ++indexBit;
        }
        return indexBit;
    }

    bool IsBit1(int num, unsigned int indexBit)
    {
        num = num >> indexBit;
        return num & 1;
    }
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size() < 3)
            return;

        int resultExclusiveOR = 0;
        for(int i = 0; i < data.size(); i++)
        {
            resultExclusiveOR ^= data[i];
        }

        unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

        *num1 = *num2 = 0;
        for(int i = 0; i < data.size(); i++)
        {
            if(IsBit1(data[i], indexOf1))
                *num1 ^= data[i];
            else
                *num2 ^= data[i];
        }
    }
};