//
// Created by Zeno on 2019/12/17.
//

#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
   int val;
   struct ListNode *next;
   ListNode(int x) :
         val(x), next(NULL) {
       }
};
//思路：三指针法，先保存next节点，再使每个cur节点的next指针指向prev,使链表倒序，然后遍历链表记录数据
//特殊用例：空链表
vector<int> printListFromTailToHead(ListNode* head) {
    vector<int> vt;
    if(head == NULL){
        //head为空返回空数组
        return vt;
    }
    if(head->next == NULL){
        //链表只有一个值则返回单值数组
        vt.push_back(head->val);
        return vt;
    }
    ListNode* prev = NULL;
    ListNode* cur = head;
    ListNode* next = cur->next;
    while(cur){
        cur->next = prev;
        prev = cur;
        cur = next;
        next = next->next;
    }
    head = prev;
    cur = head;
    next = head->next;
    while(cur){
        vt.push_back(cur->val);
        cur = next;
        if(cur!=NULL)
            next = cur->next;
    }
    return vt;
}