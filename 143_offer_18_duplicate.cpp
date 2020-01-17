//
// Created by Zeno on 2020/1/17.
//
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == nullptr)
        {
            return nullptr;
        }
        if(pHead->next == nullptr)
        {
            return pHead;
        }

        ListNode* prev = pHead;
        ListNode* cur = pHead;
        ListNode* next = pHead->next;

        while(cur)
        {
            if(next != nullptr && cur->val == next->val)
            {
                int duplicate_val = cur->val;
                //prev = cur;
                cur = next;

                while(next != nullptr && duplicate_val == next->val)
                {
                    next = next->next;
                    delete cur;
                    cur = next;
                }

                if(prev->val == duplicate_val)
                {
                    delete prev;
                    prev = cur;
                    pHead = cur;
                }
                else
                {
                    prev->next = cur;
                }
                if(next != nullptr)
                {
                    next = next->next;
                }
            }
            else
            {
                prev = cur;
                cur = next;
                if(next != nullptr)
                {
                    next = next->next;
                }
            }
        }
        return pHead;
    }
};
