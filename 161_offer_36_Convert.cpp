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
public:
    void ConvertNode(TreeNode* pNode, TreeNode** pLastNode)
    {
        if(pNode == nullptr)
        {
            return;
        }

        if(pNode->left)
        {
            ConvertNode(pNode->left, pLastNode);
        }

        pNode->left = *pLastNode;
        if(*pLastNode != nullptr)
        {
            (*pLastNode)->right = pNode;
        }

        *pLastNode = pNode;

        if(pNode->right)
        {
            ConvertNode(pNode->right, pLastNode);
        }
    }
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* pLastNode = nullptr;

        ConvertNode(pRootOfTree, &pLastNode);

        while(pLastNode && pLastNode->left)
        {
            pLastNode = pLastNode->left;
        }
        return pLastNode;
    }
};