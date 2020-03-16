//
// Created by Zeno on 2020/3/15.
//

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(head == nullptr)
        {
            return nullptr;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i = 0; i < k; i++)
        {
            if(fast)
                fast = fast->next;
            else
                return nullptr;
        }

        while(fast)
        {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};