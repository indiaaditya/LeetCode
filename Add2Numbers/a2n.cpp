#include <iostream>
using namespace std;

#define NODE_HEAD       1
#define NODE_NEXT       2
/**
 * Definition for singly-linked list.*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *retNodeFirst;
        ListNode *nextNode;
        int cntr = 0;
        int i;
        while ((l1 != NULL) && (l2 != NULL))
        {
            i = (l1->val + l2->val);
            if (carry == 1)
            {
                i++;
                carry = 0;
            }
            if (i > 9)
            {
                carry = 1;
                i -= 10;
            }

            if (cntr == 0)
                retNodeFirst = createNode(i,NODE_HEAD,NULL);
            else
            {
                if (cntr == 1)
                    nextNode = createNode(i,NODE_NEXT,retNodeFirst);
                else
                    nextNode = createNode(i,NODE_NEXT,nextNode);
            }
            l1 = l1->next;
            l2 = l2->next;
            cntr++;
        }
        while (l1 != NULL)
        {
            i = l1->val;
            if (carry == 1)
            {
                i++;
                carry = 0;
            }
            if (i > 9)
            {
                carry = 1;
                i -= 10;
            }

            nextNode = createNode(l1->val, NODE_NEXT,nextNode);
            l1 = l1->next;
            cntr++;
        }
        while (l2 != NULL)
        {
            i = l2->val;
            if (carry == 1)
            {
                i++;
                carry = 0;
            }
            if (i > 9)
            {
                carry = 1;
                i -= 10;
            }
            nextNode = createNode(i,NODE_NEXT,nextNode);
            l2 = l2->next;
            cntr++;
        }
        if (carry == 1)
            nextNode = createNode(1,NODE_NEXT,nextNode);
        return retNodeFirst;
    }

    ListNode *createNode(int rData, int nodeType, ListNode *prevNode){
        ListNode *node;
        node = new ListNode();
        node->val = rData;        
        node->next = NULL;
        if(nodeType == NODE_NEXT)
            prevNode->next = node;
        return node;
    } 

    /*ListNode *createHeadNode(int rData)
    {
        ListNode *nodeHead;
        nodeHead = new ListNode();
        nodeHead->val = rData;
        nodeHead->next = NULL;
        return nodeHead;
    }

    ListNode *createNextNode(int rData, ListNode *rPrevNode)
    {
        ListNode *nodeNext;
        nodeNext = new ListNode();
        nodeNext->val = rData;
        nodeNext->next = NULL;
        rPrevNode->next = nodeNext;
        return nodeNext;
    }*/

    void printList(ListNode *n)
    {
        cout << "\n Print List:";
        while (n != NULL)
        {
            cout << n->val << " ";
            n = n->next;
        }
    }

    ListNode *prefillNode(int *data, int cntr)
    {
        ListNode *nodeFirst;
        nodeFirst = createNode(*data,NODE_HEAD,NULL);
        cntr--;
        data++;
        ListNode *nodeNext;
        nodeNext = createNode(*data, NODE_NEXT,nodeFirst);
        cntr--;
        data++;
        for (int i = 0; i < cntr; i++)
        {
            nodeNext = createNode(*data,NODE_NEXT,nodeNext);
            data++;
        }
        return nodeFirst;
    }
};

int main()
{
    //declaration of nodes
    ListNode *l1;
    ListNode *l2;
    ListNode *l3;
    int firstArr[] = {5};
    int secondArr[] = {5};

    Solution s1;
    l1 = s1.prefillNode(firstArr, 4);
    l2 = s1.prefillNode(secondArr, 4);
    s1.printList(l1);
    s1.printList(l2);
    l3 = s1.addTwoNumbers(l1, l2);
    s1.printList(l3);
    cout << "\nComplete\n";
}