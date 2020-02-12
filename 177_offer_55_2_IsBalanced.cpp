//
// Created by Zeno on 2020/2/12.
//

class Solution {
public:
    bool IsBalanced(TreeNode* pRoot, int* pDepth)
    {
        if(pRoot == nullptr){
            *pDepth = 0;
            return true;
        }

        int left, right;
        if(IsBalanced(pRoot->left, &left) &&
           IsBalanced(pRoot->right, &right))
        {
            int diff = left - right;
            if(diff <= 1 && diff >= -1)
            {
                *pDepth = 1 + max(left, right);
                return true;
            }
        }
        return false;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth = 0;
        return IsBalanced(pRoot, &depth);
    }
};