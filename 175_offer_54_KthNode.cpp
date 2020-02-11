//
// Created by Zeno on 2020/2/11.
//

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == nullptr || k == 0)
            return nullptr;

        stack<TreeNode*> st;
        TreeNode* cur = pRoot;
        int count = 0;
        while(cur || !st.empty())
        {
            if(cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = st.top();
                st.pop();

                count++;
                if(count == k)
                    return cur;

                cur = cur->right;
            }
        }
        return nullptr;
    }
};