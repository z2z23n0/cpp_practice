//
// Created by Zeno on 2020/3/9.
//

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(nullptr == root)
            return 0;

        queue<TreeNode*> que;
        que.push(root);

        TreeNode* levelLast = root;
        int level = 0;

        while(!que.empty())
        {
            TreeNode* cur = que.front();
            que.pop();

            if(cur->left)
                que.push(cur->left);
            if(cur->right)
                que.push(cur->right);

            if(cur == levelLast)
            {
                levelLast = que.back();
                level++;
            }
        }

        return level;
    }
};