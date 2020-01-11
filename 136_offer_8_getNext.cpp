//
// Created by Zeno on 2020/1/11.
//

#include <queue>

using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(nullptr), right(nullptr), next(nullptr) {

    }
};

//测试用例：
// 1. 传入nullptr
// 2. 传入根节点
// 3. 传入的节点是最后一个节点

class Solution {
public:

    queue<TreeLinkNode*> nodes;

    void Inorder(TreeLinkNode* pRoot)
    {
        if(pRoot == nullptr)
        {
            return;
        }

        Inorder(pRoot->left);
        nodes.push(pRoot);
        Inorder(pRoot->right);
    }

    TreeLinkNode* GetRoot(TreeLinkNode* pNode)
    {
        TreeLinkNode* root = nullptr;
        TreeLinkNode* cur = pNode;
        TreeLinkNode* prev = cur->next;
        while (prev)
        {
            cur = prev;
            prev = prev->next;
        }
        return cur;
    }
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {

        if(pNode == nullptr)
        {
            return nullptr;
        }

        TreeLinkNode* root = GetRoot(pNode);//获取根节点

        Inorder(root);//中序遍历根节点

        TreeLinkNode* ret;
        while (!nodes.empty())
        {
            TreeLinkNode* node = nodes.front();
            if(node == pNode)
            {
                nodes.pop();
                ret = nodes.front();
                while(!nodes.empty())
                {
                    nodes.pop();
                }
                return ret;
            }
            else
            {
                nodes.pop();
            }
        }
        return nullptr;
    }
};
