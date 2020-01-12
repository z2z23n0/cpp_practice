//
// Created by Zeno on 2020/1/12.
//

#include <iostream>
#include <vector>
using namespace std;

int minNumberInRotateArray(vector<int> rotateArray) {
    if(rotateArray.size() == 0){
        return 0;
    }

    unsigned int mid = rotateArray.size()/2;
    unsigned int first = 0;
    unsigned int second = rotateArray.size() - 1;
    while(rotateArray[first] >= rotateArray[second])
    {
        if(first + 1 == second)
        {
            break;
        }
        mid = (first + second) / 2;
        if(rotateArray[mid] >= rotateArray[first])
        {
            first = mid;
            //continue;
        }
        else if(rotateArray[mid] <= rotateArray[second])
        {
            second = mid;;
            //continue;
        }
    }
    return rotateArray[second];
}
