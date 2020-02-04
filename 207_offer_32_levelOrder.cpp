//
// Created by Zeno on 2020/3/14.
//

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> v;
        if(root == nullptr)
            return v;
        queue<TreeNode*> que;

        que.push(root);
        while(!que.empty())
        {
            TreeNode* cur = que.front();
            que.pop();

            if(cur->left)
                que.push(cur->left);
            if(cur->right)
                que.push(cur->right);

            v.push_back(cur->val);
        }

        return v;
    }
};