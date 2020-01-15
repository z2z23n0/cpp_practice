//
// Created by Zeno on 2020/2/23.
//

class Solution {
public:
    int Add(int num1, int num2)
    {
        if(num2 == 0)
            return num1;

        int sum, carry;
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;

        return Add(sum, carry);
    }
};