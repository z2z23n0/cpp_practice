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
};
*/
/*
测试用例：
1. 带环
2. 不带环
3. nullptr
*/
class Solution {
public:
    ListNode* MeetingNode(ListNode* pHead)
    {
        if(pHead == nullptr)
        {
            return nullptr;
        }

        ListNode* fast = pHead;
        ListNode* slow = pHead;

        while(fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
            {
                return fast;
            }
        }
        if(fast->next == nullptr)
        {
            return nullptr;
        }
    }
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead == nullptr)
        {
            return nullptr;
        }

        ListNode* meet = MeetingNode(pHead);
        if(meet == nullptr)
        {
            return nullptr;
        }

        ListNode* next = meet->next;
        int count = 0;
        while(next!=meet)
        {
            next = next->next;
            count++;
        }
        int loop_nodes = ++count;

        ListNode* fast = pHead;
        ListNode* slow = pHead;
        while(count > 0)
        {
            fast = fast->next;
            --count;
        }
        while(fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};