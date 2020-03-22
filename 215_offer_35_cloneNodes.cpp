//
// Created by Zeno on 2020/3/17.
//

class Solution {
public:
    void cloneNodes(Node* head)
    {
        Node* cur = head;
        while(cur)
        {
            Node* newNode = new Node(cur->val);
            newNode->next = cur->next;
            newNode->random = nullptr;

            cur->next = newNode;
            cur = newNode->next;
        }
    }

    void connectRandomNodes(Node* head)
    {
        Node* cur = head;
        while(cur)
        {
            if(cur->random)
            {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
    }

    Node* splitNodes(Node* head)
    {
        Node* cur = head;
        Node* clonedHead = cur->next;
        Node* clonedCur = cur->next;

        while(cur)
        {
            cur->next = clonedCur->next;
            cur = cur->next;
            if(clonedCur&&cur)
            {
                clonedCur->next = cur->next;
                clonedCur = clonedCur->next;
            }
        }

        return clonedHead;
    }

    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return nullptr;

        cloneNodes(head);
        connectRandomNodes(head);
        return splitNodes(head);
    }
};