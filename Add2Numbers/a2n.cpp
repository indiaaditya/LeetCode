#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.*/
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     int carry = 0;
     ListNode* retNode = new ListNode();   
     while( (l1 != NULL) && (l2 != NULL)){
         retNode->val = (l1->val + l2->val);
         retNode->next = NULL;
         if(carry == 1){
             retNode->val++;
             carry = 0;
         }
         if(retNode->val > 9){
             carry = 1;
             retNode->val -= 10;
         }
         l1 = l1->next;
         l2 = l2->next;
         retNode = retNode->next;
     }
     while(l1 != NULL){
         retNode->val = l1->val;
         l1 = l1->next;
         retNode = retNode->next;
     }
     while(l2 != NULL){
         retNode->val = l2->val;
         l2 = l2->next;
         retNode = retNode->next;
     }
     
     return retNode;      
    }

    ListNode* createHeadNode(int rData){
        ListNode *nodeHead;
        nodeHead = new ListNode();
        nodeHead->val = rData;
        nodeHead->next = NULL;
        return nodeHead;
    }

    ListNode* createNextNode(int rData, ListNode* rPrevNode){
        ListNode *nodeNext;
        nodeNext = new ListNode();
        nodeNext->val = rData;
        nodeNext->next = NULL;
        rPrevNode->next = nodeNext;
        return nodeNext;
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

    ListNode* prefillNode(int* data, int cntr){
        ListNode *nodeFirst;    
        nodeFirst = createHeadNode(*data);
        cntr--;
        data++;
        ListNode *nodeNext;
        nodeNext = createNextNode(*data,nodeFirst);
        cntr--;
        data++;
        for(int i = 0; i < cntr; i++){
            nodeNext = createNextNode(*data,nodeNext);
            data++;
        }
        return nodeFirst;
    } 
};


int main(){
    //declaration of nodes
    ListNode *l1;
    ListNode *l2;

    int firstArr[4] = {7,8,9,1};
    int secondArr[4] = {4,6,7,3};

    Solution s1;
    l1 = s1.prefillNode(firstArr,4);
    l2 = s1.prefillNode(secondArr,4);
    s1.printList(l1);
    s1.printList(l2);

    cout<< "\nComplete\n"; 
}