//
// Created by Zeno on 2019/11/22.
//

#include <iostream>

namespace zyz{
template <class T> class TreeNode;
template <class T> class BinarySortTree;
template <class T>
class TreeNode{
    T m_data;
    TreeNode<T>* m_left;
    TreeNode<T>* m_right;
public:
    TreeNode(const T & val = T()) :
        m_data(val),
        m_left(nullptr),
        m_right(nullptr)
    {

    }
    template <class T>
    friend class BinarySortTree;
};
template <class T>
class BinarySortTree{
    TreeNode<T> * m_root;
};
}

