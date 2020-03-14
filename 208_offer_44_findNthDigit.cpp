//
// Created by Zeno on 2020/3/15.
//

class Solution {
public:
    int findNthDigit(int n) {
        // 计算目标数字是几位数
        long base = 9, digits = 1;
        while(n - base * digits > 0)
        {
            n -= base * digits;
            base *= 10;
            digits++;
        }
        // 此时n已经变成：digits位数中的第n个

        // 计算出n是目标数字的第几位
        int index = n % digits;
        if(index == 0)
            index = digits;

        // 计算出目标数字
        int number = 1;
        for(int i = 1; i < digits; ++i)
            number *= 10;
        number += (index == digits) ? n / digits - 1 : n / digits;

        // 计算出结果
        for(int i = index; i < digits; ++i)
        {
            number /= 10;
        }

        return number % 10;
    }
};