//
// Created by Zeno on 2020/1/10.
//

#include <cstdlib>

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

void AddToTail(ListNode** pHead, int value)
{
    ListNode* pNew;
    pNew->m_nValue = value;
    pNew->m_pNext = nullptr;

    if(pHead == nullptr || *pHead == nullptr)
    {
        *pHead = pNew;
        return;
    }

    ListNode* cur = *pHead;
    ListNode* next = (*pHead)->m_pNext;

    while(next)
    {
        cur = next;
        next = next->m_pNext;
    }
    cur->m_pNext = pNew;
    return;
}

void RemoveNode(ListNode** pHead, int value)
{
    if(pHead == nullptr || *pHead == nullptr)
    {
        return;
    }

    ListNode* prev = nullptr;
    ListNode* cur = *pHead;
    ListNode* next = (*pHead)->m_pNext;

    if(cur->m_nValue == value)
    {
        *pHead = next;
        return;
    }

    while(next)
    {
        if(cur->m_nValue == value)
        {
            free(cur);
            cur = nullptr;
            prev->m_pNext = next;
            return;
        }
        prev = cur;
        cur = next;
        next = next->m_pNext;
    }
}
