//
// Created by Zeno on 2020/1/25.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size() == 0)
        {
            return false;
        }

        //int root = *(sequence.end() - 1);
        vector<int>::iterator root = sequence.end() - 1;

        //int i = 0;
        vector<int>::iterator left = sequence.begin();
        for(;left != sequence.end(); left++)
        {
            if(*left > *root)
            {
                break;
            }
        }

        vector<int>::iterator right = left;
        for(; right != sequence.end(); right++)
        {
            if(*right < *root)
            {
                return false;
            }
        }

        bool isLeft = true;
        bool isRight = true;
        if(left - 1 > sequence.begin())
        {
            vector<int> sequence_left;
            sequence_left.assign(sequence.begin(), left);
            isLeft = VerifySquenceOfBST(sequence_left);
        }

        if(left < sequence.end())
        {
            vector<int> sequence_right;
            //vector<int>::iterator right_end = sequence.end() - 1;
            sequence_right.assign(left, sequence.end() - 1);
            isRight = VerifySquenceOfBST(sequence_right);
        }

        return (isLeft && isRight);
    }
};

int main()
{
    Solution s;
    vector<int> v({5,7,6,9,11,10,8});

    cout<<s.VerifySquenceOfBST(v);
    return 0;
}
