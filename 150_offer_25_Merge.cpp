//
// Created by Zeno on 2020/1/20.
//


/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
/*
测试用例：
1. 一个或两个链表头节点为nullptr
2. 节点值相同时
3. 链表中只有一个节点
*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(nullptr == pHead1)
        {
            return pHead2;
        }
        if(nullptr == pHead2)
        {
            return pHead1;
        }
        ListNode* prev = nullptr;
        ListNode* newHead = prev;
        ListNode* pL1 = pHead1;
        ListNode* pL2 = pHead2;

        if(pL1->val < pL2->val)
        {
            prev = pL1;
            pL1 = pL1->next;
            newHead = prev;
        }
        else
        {
            prev = pL2;
            pL2 = pL2->next;
            newHead = prev;
        }
        while(pL1 != nullptr && pL2 != nullptr)
        {
            if(pL1->val < pL2->val)
            {
                prev->next = pL1;
                pL1 = pL1->next;
                prev = prev->next;
            }
            else
            {
                prev->next = pL2;
                pL2 = pL2->next;
                prev = prev->next;
            }
        }
        if(nullptr == pL1)
        {
            prev->next = pL2;
        }
        else
        {
            prev->next = pL1;
        }
        return newHead;
    }
};