//
// Created by Zeno on 2020/2/29.
//

class Solution {
public:
    int jumpFloor(int number) {
        if(number == 0)
            return 0;
        if(number == 1)
            return 1;

        int third = 0, second = 1;
        int first = third + second;
        for(int count = 0; count < number; count++)
        {
            first = third + second;
            third = second;
            second = first;
        }

        return first;
    }
};