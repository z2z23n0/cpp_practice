//
// Created by Zeno on 2020/3/11.
//

class Solution {
public:
    int countDigitOne(int n) {

        int ret = 0;
        for(long i = 1; i <= n; i *= 10)
        {
            long cur = n / i % 10;
            long high = n / i / 10;
            long low = n % i;

            if(cur == 0)
            {
                ret += high * i;
            }
            else if(cur == 1)
            {
                ret += high * i + low + 1;
            }
            else
            {
                ret += (high + 1) * i;
            }
        }

        return ret;
    }
};