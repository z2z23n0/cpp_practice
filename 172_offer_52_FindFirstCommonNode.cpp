//
// Created by Zeno on 2020/2/7.
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* cur1 = pHead1;
        ListNode* cur2 = pHead2;
        int count1 = 0;
        int count2 = 0;
        while(cur1)
        {
            count1++;
            cur1 = cur1->next;
        }
        while(cur2)
        {
            count2++;
            cur2 = cur2->next;
        }

        cur1 = pHead1;
        cur2 = pHead2;
        int diff;
        if(count1 > count2)
        {
            diff = count1 - count2;
            while(diff)
            {
                cur1 = cur1->next;
                diff--;
            }
        }
        else
        {
            diff = count2 - count1;
            while(diff)
            {
                cur2 = cur2->next;
                diff--;
            }
        }

        while(cur1 != nullptr && cur2 != nullptr)
        {
            if(cur1 == cur2)
                return cur1;
            else
            {
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
        }
        return nullptr;
    }
};