//
// Created by Zeno on 2020/1/22.
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
    void Mirror(TreeNode *pRoot) {
        if(pRoot == nullptr)
        {
            return;
        }
        stack<TreeNode*> s;
        s.push(pRoot);
        while(!s.empty())
        {
            TreeNode* top = s.top();
            s.pop();

            TreeNode* temp = top->left;
            top->left = top->right;
            top->right = temp;

            if(top->right)
            {
                s.push(top->right);
            }
            if(top->left)
            {
                s.push(top->left);
            }
        }
        return;
    }
};