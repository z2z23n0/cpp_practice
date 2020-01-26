//
// Created by Zeno on 2020/1/26.
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
private:
    vector<vector<int>> ret;
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root == nullptr)
        {
            return ret;
        }

        vector<int> path;
        int currentSum = 0;
        FindPath(root, expectNumber, path, currentSum);

        return ret;
    }

    void FindPath(TreeNode* root, int expectNumber,
                  vector<int>& path, int currentSum)
    {
        currentSum += root->val;
        path.push_back(root->val);

        if(root->left == nullptr && root->right == nullptr
           && currentSum == expectNumber)
        {
            ret.push_back(path);
        }

        if(root->left)
        {
            FindPath(root->left, expectNumber, path, currentSum);
        }

        if(root->right)
        {
            FindPath(root->right, expectNumber, path, currentSum);
        }

        path.pop_back();
    }
};