//
// Created by Zeno on 2020/1/19.
//

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(nullptr == pHead)
        {
            return nullptr;
        }
        if(nullptr == pHead->next)
        {
            return pHead;
        }

        ListNode* prev = nullptr;
        ListNode* cur = pHead;
        ListNode* next = pHead->next;

        while(next)
        {
            cur->next = prev;
            prev = cur;
            cur = next;
            next = next->next;
        }
        cur->next = prev;
        return cur;
    }
};
