//
// Created by Zeno on 2020/3/9.
//

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A || !B)
            return false;

        return dfs(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    bool dfs(TreeNode* A, TreeNode* B)
    {
        if(!B)
            return true;
        if(!A)
            return false;

        return (A->val == B->val) && dfs(A->left, B->left) && dfs(A->right, B->right);
    }
};