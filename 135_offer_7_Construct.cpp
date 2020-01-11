//
// Created by Zeno on 2020/1/11.
//

#include <exception>
#include <iostream>
using namespace std;

struct BinaryTreeNode
{
    int m_value;
    BinaryTreeNode* m_left;
    BinaryTreeNode* m_right;
};

//测试用例：
// 1. 普通二叉树（完全二叉树、不完全二叉树）
// 2. 特殊二叉树（所有节点都没有右子节点的二叉树，所有节点都没有左子节点的二叉树，只有一个节点的二叉树）
// 3. 特殊输入测试（二叉树的根节点指针为nullptr，输入的前序遍历序列和中序遍历序列不匹配）

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder,
                              int* startInorder, int* endInorder)
{
    //前序遍历序列的第一个数字是根节点的值
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();//创建一个root节点
    root->m_value = rootValue;
    root->m_left = root->m_right = nullptr;

    if(startPreorder == endPreorder)//前序遍历序列第一个和最后一个节点是同一个节点
    {
        if(*startInorder == *endInorder && *startPreorder == *startInorder)
        {
            //测试用例2第三条情况
            return root;
        }
        else
        {
            //测试用例3第二条情况
            throw std::exception();//输入错误
        }
    }

    // 在中序遍历序列中找到根节点的值
    int* rootInorder = startInorder;
    while(rootInorder <= endInorder && *rootInorder != rootValue)
    {
        ++rootInorder;
    }

    //中序遍历中没找到根节点说明输入错误
    if(rootInorder == endInorder && *rootInorder != rootValue)
    {
        throw std::exception();
    }

    int leftLength = rootInorder - startInorder;//根的左子树总节点数
    int* leftPreorderEnd = startPreorder + leftLength;//前序遍历中根的左子树节点的结束位置
    if(leftLength > 0)
    {
        //构建左子树
        root->m_left = ConstructCore(startPreorder + 1, leftPreorderEnd,
                                     startInorder, rootInorder - 1);
    }
    if(leftLength < endPreorder - startPreorder)
    {
        //构建右子树
        root->m_right = ConstructCore(leftPreorderEnd + 1, endPreorder,
                                      rootInorder + 1, endInorder);
    }
    return root;
}

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
    if(preorder == nullptr || inorder == nullptr || length < 0)
    {
        //测试用例3第一条的情况
        return nullptr;
    }

    return  ConstructCore(preorder, preorder + length - 1,
            inorder, inorder + length - 1);
}

