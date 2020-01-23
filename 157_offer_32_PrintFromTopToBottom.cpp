//
// Created by Zeno on 2020/1/23.
//


/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> v;
        if(root == nullptr)
        {
            return v;
        }
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();
            v.push_back(cur->val);

            if(cur->left)
            {
                q.push(cur->left);
            }
            if(cur->right)
            {
                q.push(cur->right);
            }
        }
        return v;
    }
};