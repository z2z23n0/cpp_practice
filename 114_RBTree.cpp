//
// Created by Zeno on 2019/12/14.
//

#include "114_RBTree.h"

int main(){
    wf::RBTree<int> rbt;
    rbt.insert(1);
    rbt.insert(2);
    rbt.insert(3);
    rbt.insert(4);

    rbt.test();
    return 0;
}