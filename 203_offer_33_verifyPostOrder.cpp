//
// Created by Zeno on 2020/3/11.
//
class Solution {
public:
    bool helper(vector<int>& post, int low, int high)
    {
        if(low >= high)
            return true;

        int root = post[high];
        int left = low;
        while(left < high && post[left] < root)
        {
            left++;
        }

        int right = left;
        while(left < high && post[right] > root)
        {
            right++;
        }

        if(right != high)
        {
            return false;
        }

        return helper(post, low, left - 1) && helper(post, left, right - 1);
    }
    bool verifyPostorder(vector<int>& postorder) {
        return helper(postorder, 0, postorder.size() - 1);
    }
};
