//
// Created by Zeno on 2020/1/18.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int>::iterator slow = array.begin();
        vector<int>::iterator fast = slow + 1;

        while(fast != array.end())
        {
            if((*slow % 2) != 0)
            {
                slow++;
                continue;
            }
            fast = slow + 1;

            while(fast != array.end())
            {
                if(*fast % 2 == 0)
                {
                    fast++;
                }
                else
                {
                    swap(*slow,*fast);
                    slow++;
                    break;
                }
            }

        }
    }
};
