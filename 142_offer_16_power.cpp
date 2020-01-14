//
// Created by Zeno on 2020/1/14.
//

class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent == 0 || base == 1)
        {
            return 1;
        }
        if(base == 0)
        {
            return 0;
        }
        double ret = 1;
        if(exponent > 0)
        {

            for(int i = 0; i < exponent; i++)
            {
                ret *= base;
            }
            return ret;
        }
        else
        {
            exponent*=-1;
            for(int i = 0; i < exponent; i++)
            {
                ret *= base;
            }
            return 1/ret;
        }
    }
};
