//
// Created by Zeno on 2020/2/21.
//

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size() == 0)
            return false;

        sort(numbers.begin(), numbers.end());

        int countZero = 0;
        int countGap = 0;

        for(int i = 0; i < numbers.size() && numbers[i] == 0; ++i)
        {
            ++countZero;
        }

        int small = countZero;
        int big = small + 1;
        while(big < numbers.size())
        {
            if(numbers[big] == numbers[small])
                return false;

            countGap += numbers[big] - numbers[small] - 1;
            small = big;
            ++big;
        }

        return (countGap <= countZero) ? true : false;
    }
};