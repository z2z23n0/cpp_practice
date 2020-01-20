//
// Created by Zeno on 2020/1/19.
//

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class BinaryTreeNode
{
public:
    char m_data;
    BinaryTreeNode* m_left;
    BinaryTreeNode* m_right;
};

//通过前序遍历的数组构建二叉树
BinaryTreeNode* BinaryTreeCreat(char* a, int* pi)
{
    if(a[*pi] != '#')
    {
        BinaryTreeNode* root = new BinaryTreeNode;
        root->m_data = a[*pi];
        ++(*pi);
        root->m_left = BinaryTreeCreat(a, pi);
        ++(*pi);
        root->m_right = BinaryTreeCreat(a, pi);
        return root;
    }
    else
    {
        return NULL;
    }
}

void BinaryTreeDestory(BinaryTreeNode** root)
{
    BinaryTreeNode* curRoot = *root;
    if(curRoot)
    {
        BinaryTreeDestory(&curRoot->m_left);
        BinaryTreeDestory(&curRoot->m_right);
        free(curRoot);
        *root = NULL;
    }
}

//递归前序遍历
void BinaryTreePrevOrder(BinaryTreeNode* root)
{
    if(root)
    {
        printf("%c ", root->m_data);
        BinaryTreePrevOrder(root->m_left);
        BinaryTreePrevOrder(root->m_right);
    }
}

//递归中序遍历
void BinaryTreeInOrder(BinaryTreeNode* root)
{
    if(root)
    {
        BinaryTreeInOrder(root->m_left);
        printf("%c ", root->m_data);
        BinaryTreeInOrder(root->m_right);
    }
}

//递归后序遍历
void BinaryTreePostOrder(BinaryTreeNode* root)
{
    if(root)
    {
        BinaryTreePostOrder(root->m_left);
        BinaryTreePostOrder(root->m_right);
        printf("%c ", root->m_data);
    }
}

//非递归前序遍历
void BinaryTreePrevOrderNonR(BinaryTreeNode* root)
{
    BinaryTreeNode* cur = root;
    stack<BinaryTreeNode*> st;

    while(cur || !st.empty())
    {
        while (cur)
        {
            printf("%c ", cur->m_data);
            st.push(cur);
            cur = cur->m_left;
        }

        cur = st.top()->m_right;
        st.pop();
    }
}

//非递归中序遍历
void BinaryTreeInOrderNonR(BinaryTreeNode* root)
{
    BinaryTreeNode* cur = root;
    stack<BinaryTreeNode*> st;

    while(cur || !st.empty())
    {
        while (cur)
        {
            st.push(cur);
            cur = cur->m_left;
        }

        cur = st.top();
        st.pop();
        printf("%c ", cur);

        cur = cur->m_right;
    }
}

//非递归后序遍历
void BinaryTreePostOrderNonR(BinaryTreeNode* root)
{
    BinaryTreeNode* cur = root;
    BinaryTreeNode* top;
    BinaryTreeNode* prev = nullptr;
    stack<BinaryTreeNode*> st;

    while(cur || !st.empty())
    {
        //把所有的左子树节点压栈
        while(cur)
        {
            st.push(cur->m_left);
            cur = cur->m_left;
        }

        //判断栈顶节点是否存在右子树
        //如果不存在，或右子树已经被访问过，则访问根，出栈
        //如果存在，且没访问过则访问
        if(st.top() == nullptr || st.top() == prev)
        {
            printf("%c ", st.top()->m_data);
            prev = st.top();
            st.pop();
        }
        else
        {
            cur = st.top()->m_right;
        }
    }
}

void BinaryTreeLevelOrder(BinaryTreeNode* root)
{
    queue<BinaryTreeNode*> q;
    if(nullptr != root)
    {
        q.push(root);
    }

    while(!q.empty())
    {
        printf("%c ", q.front()->m_data);
        if(q.front()->m_left)
            q.push(q.front()->m_left);
        if(q.front()->m_right)
            q.push(q.front()->m_right);
        q.pop();
    }
}
