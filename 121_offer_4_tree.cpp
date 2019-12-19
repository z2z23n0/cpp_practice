//
// Created by Zeno on 2019/12/19.
//

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    //判定递归终止条件
    if(pre.size() == 0 || vin.size() == 0) {
        return NULL;
    }
    //找出根节点(前序遍历的第一个节点)
    int root = pre[0];
    //创建新节点
    TreeNode* node = new TreeNode(root);
    vector<int>::iterator it;
    //1. 求左右子树的遍历序列
    vector<int> preLeft,preRight,inLeft,inRight;
        //(1)求根节点在中序遍历中的位置
    vector<int>::iterator i;
    for(it = vin.begin();it != vin.end();it++){
        if(root == *it){
            i = it;
        }
    }
        //(2)求左右子树的中序遍历子序列
    int k = 0;
    for(it = vin.begin();it != vin.end();it++){
        if( k == 0){
            inLeft.push_back(*it);
        }else if(k == 1){
            inRight.push_back(*it);
        }
        if(it == i){
            k = 1;
        }
    }
        //(3) 求左右子树的前序遍历子序列
    k = 0;
    vector<int>::iterator ite;
    for(it = pre.begin() + 1;it != pre.end(); it++){
        for(ite = inLeft.begin(); ite != inLeft.end(); ite++){
            if(*it == *ite){
                preLeft.push_back(*it);
                k = 1;
            }
        }
        if(k == 0){
            preRight.push_back(*it);
        }
        k = 0;
    }
    node->left = reConstructBinaryTree(preLeft,inLeft);
    node->right = reConstructBinaryTree(preRight,inRight);
    return node;
}