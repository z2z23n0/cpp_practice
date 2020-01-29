//
// Created by Zeno on 2020/1/29.
//

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int count = 0;
        for(int i = 1; i <= n; i++)
        {
            count += NumberOf1(i);
        }
        return count;
    }
    int NumberOf1(int n)
    {
        int count = 0;
        while(n)
        {
            if(n %10 == 1)
            {
                count++;
            }

            n /= 10;
        }
        return count;
    }
};