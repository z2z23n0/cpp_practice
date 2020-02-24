//
// Created by Zeno on 2020/3/9.
//

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(nullptr == root)
            return 0;

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};