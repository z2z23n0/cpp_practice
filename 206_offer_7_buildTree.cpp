//
// Created by Zeno on 2020/3/14.
//

class Solution {
public:
    TreeNode* helper(vector<int>::iterator preBegin, vector<int>::iterator preEnd,
                     vector<int>::iterator inBegin, vector<int>::iterator inEnd)
    {
        if(preBegin == preEnd)
            return nullptr;

        TreeNode* cur = new TreeNode(*preBegin);
        vector<int>::iterator root = find(inBegin, inEnd, *preBegin);

        cur->left = helper(preBegin + 1, preBegin + (root - inBegin) + 1, inBegin, root);
        cur->right = helper(preBegin + (root - inBegin) + 1, preEnd, root + 1, inEnd);
        return cur;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder.begin(), preorder.end(),
                      inorder.begin(), inorder.end());
    }
};