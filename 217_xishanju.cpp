//
// Created by Zeno on 2020/3/22.
//

#include <iostream>
using namespace std;

int helper(int sum)
{
    if(sum < 3)
        return 0;

    int small = 1;
    int big = 2;
    int middle = (1 + sum) / 2;
    int curSum = small + big;
    int count = 0;

    while(small < middle)
    {
        if(curSum == sum)
            count++;

        while(curSum > sum && small < middle)
        {
            curSum -= small;
            small += 2;

            if(curSum == sum)
                count++;
        }

        big += 2;
        curSum += big;
    }
    return count;
}

int main()
{
    cout<< helper(16) <<endl;
    return 0;
}