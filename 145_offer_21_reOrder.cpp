//
// Created by Zeno on 2020/1/18.
//

#include <iostream>
#include <vector>
//#include <algorithm>

using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int>::iterator begin = array.begin();
        vector<int>::iterator end = array.end();

        while(begin < end)
        {
            if((*begin % 2) != 0)
            {
                begin++;
                continue;
            }
            if((*end % 2) == 0)
            {
                end--;
                continue;
            }

            swap(*begin,*end);
        }
    }
};
