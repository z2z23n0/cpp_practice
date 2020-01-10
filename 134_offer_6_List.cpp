//
// Created by Zeno on 2020/1/10.
//

#include "133_List.cpp"
#include <iostream>
#include <stack>

using namespace std;

void PrintListReversingly_Iteratively(ListNode* pHead)
{
    if(pHead == nullptr)
    {
        return;
    }

    std::stack<ListNode*> nodes;

    ListNode* cur = pHead;
    ListNode* next = pHead->m_pNext;

    while (next)
    {
        nodes.push(cur);

        cur = next;
        next = next->m_pNext;
    }
    nodes.push(cur);

    while (!nodes.empty())
    {
        cout << nodes.top()->m_nValue << endl;
        nodes.pop();
    }
}
