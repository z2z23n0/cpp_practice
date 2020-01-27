//
// Created by Zeno on 2020/1/28.
//

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size() == 0)
        {
            return 0;
        }

        int num = 0, count = 0;

        vector<int>::iterator it;
        for(it = numbers.begin(); it != numbers.end(); it++)
        {
            if(*it == num)
            {
                count++;
                continue;
            }
            else
            {
                count--;
            }

            if(count < 0)
            {
                num = *it;
                count = 0;
            }
        }

        int test_count = 0;
        for(it = numbers.begin(); it != numbers.end(); it++)
        {
            if(*it == num)
            {
                test_count++;
            }
        }

        return (test_count > numbers.size() / 2) ? num : 0;
    }
};