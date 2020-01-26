//
// Created by Zeno on 2020/1/26.
//

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    void CloneNodes(RandomListNode* pHead)
    {
        RandomListNode* pNode = pHead;

        while(pNode)
        {
            RandomListNode* pCloned = new RandomListNode(pNode->label);
            pCloned->next = pNode->next;

            pNode->next = pCloned;

            pNode = pCloned->next;
        }
    }

    void ConnectRandom(RandomListNode* pHead)
    {
        RandomListNode* pNode = pHead;

        while(pNode)
        {
            RandomListNode* pCloned = pNode->next;

            if(pNode->random)
            {
                pCloned->random = pNode->random->next;
            }

            pNode = pCloned->next;
        }
    }

    RandomListNode* ReconnectNodes(RandomListNode* pHead)
    {
        RandomListNode* pClonedHead = pHead->next;
        RandomListNode* pNode = pHead;
        RandomListNode* pCloned;

        while(pNode)
        {
            pCloned = pNode->next;

            if(pCloned)
                pNode->next = pCloned->next;

            pNode = pNode->next;

            if(pNode)
                pCloned->next = pNode->next;
        }
        return pClonedHead;
    }

    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == nullptr)
        {
            return nullptr;
        }

        CloneNodes(pHead);
        ConnectRandom(pHead);
        return ReconnectNodes(pHead);
    }
};