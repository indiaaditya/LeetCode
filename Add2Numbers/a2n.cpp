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

    void printList(ListNode* n) 
    { 
        cout << "\n Print List:";
        while (n != NULL) { 
        cout << n->val << " "; 
        n = n->next; 
    }

    ListNode* prefillNode(int* data, int cntr){

        return nodeHead;
    } 
} 

};


int main(){
    //declaration of nodes
    ListNode *l1;
    ListNode *l2;
    ListNode *l3;
    cout<<"\nStart\n\n\n";
    Solution s1;
    l1 = s1.createHeadNode(7);
    l2 = s1.createNextNode(8,l1);
    l3 = s1.createNextNode(9,l2);
    cout << "First Node: \n";
    s1.printList(l1);

    ListNode *n1;
    ListNode *n2;
    ListNode *n3;
    n1 = s1.createHeadNode(1);
    n2 = s1.createNextNode(2,n1);
    n3 = s1.createNextNode(3,n2);
    cout << "Second Node: \n";
    s1.printList(n1);

    cout<< "\nComplete\n"; 
}