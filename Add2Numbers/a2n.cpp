#include <iostream>
using namespace std;

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
        ListNode *prevNode;
        ListNode *firstNode;
        int isFirstNodeFlag = 0;
        prevNode = NULL;
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
            if(prevNode == NULL)
                isFirstNodeFlag = 1;
            prevNode = createNode(i,prevNode);
            if(isFirstNodeFlag == 1){
                firstNode = prevNode;
                isFirstNodeFlag = 0;
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
            if(prevNode == NULL)
                isFirstNodeFlag = 1;
            prevNode = createNode(i,prevNode);
            if(isFirstNodeFlag == 1){
                firstNode = prevNode;
                isFirstNodeFlag = 0;
            }
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
            if(prevNode == NULL)
                isFirstNodeFlag = 1;
            prevNode = createNode(i,prevNode);
            if(isFirstNodeFlag == 1){
                firstNode = prevNode;
                isFirstNodeFlag = 0;
            }
            l2 = l2->next;
            cntr++;
        }
        if (carry == 1){
            prevNode = createNode(carry,prevNode);
        }
        return firstNode;
    }

    ListNode *createNode(int rData, ListNode *prevNode){
        ListNode *node;
        node = new ListNode();
        node->val = rData;        
        node->next = NULL;
        if(prevNode != NULL)
            prevNode->next = node;
        return node;
    } 


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
        nodeFirst = createNode(*data,NULL);
        cntr--;
        data++;
        if (cntr > 0)
        {
            ListNode *nodeNext;
            nodeNext = createNode(*data,nodeFirst);
            cntr--;
            data++;
            for (int i = 0; i < cntr; i++)
            {
                nodeNext = createNode(*data,nodeNext);
                data++;
            }
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
    int firstArr[] = {2,4,3};
    int secondArr[] = {5,6,4};

    Solution s1;
    l1 = s1.prefillNode(firstArr, 3);
    l2 = s1.prefillNode(secondArr, 3);
    s1.printList(l1);
    s1.printList(l2);
    l3 = s1.addTwoNumbers(l1, l2);
    s1.printList(l3);
    cout << "\nComplete\n";
}