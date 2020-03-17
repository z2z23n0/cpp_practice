//
// Created by Zeno on 2020/3/17.
//

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head == nullptr)
            return nullptr;
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* next = head->next;

        while(cur)
        {
            if(cur->val == val)
            {
                if(prev)
                {
                    prev->next = next;
                }
                else
                {
                    head = next;
                }
                break;
            }
            prev = cur;
            cur = next;
            if(next)
                next = next->next;
        }
        return head;
    }
};