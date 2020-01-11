//
// Created by Zeno on 2020/1/11.
//

using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(nullptr), right(nullptr), next(nullptr) {

    }
};

TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
    if(pNode == nullptr)
    {
        return nullptr;
    }

    TreeLinkNode* pNext = nullptr;
    if(pNode->right != nullptr)
    {
        //Node节点的右子树不为空时,右子树的最左子节点就是下一个节点
        TreeLinkNode* pRight = pNode->right;
        while(pRight->left != nullptr)
        {
            pRight = pRight->left;
        }

        pNext = pRight;
    }
    else if(pNode->next != nullptr)
    {
        TreeLinkNode* pCur = pNode;
        TreeLinkNode* pPrev = pNode->next;
        while (pPrev != nullptr && pCur == pPrev->right)
        {
            //node节点的右子树为空，且它是它父亲节点的右孩子时，下一个节点是一直向上遍历到是它父亲节点的左孩子的节点
            pCur = pPrev;
            pPrev = pPrev->next;
        }

        //如果node节点的右子树为空，且它是它父亲节点的左孩子时，下一个节点就是它父亲

        pNext = pPrev;
    }
    return pNext;
}
