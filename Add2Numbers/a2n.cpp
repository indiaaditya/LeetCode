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

    ListNode* prefillNode(int* data, int cntr){
        ListNode *nodeHead;
        nodeHead = new ListNode();
        ListNode *nextNode;
        nextNode = new ListNode();
        for(int i = 0; i < cntr; i++){
            nodeHead->val = *data;
            nodeHead->next = nextNode;
            nodeHead = nextNode;
            nextNode = new ListNode();
            data++;
        }
    }
};


int main(){
    //declaration of nodes
    ListNode *l1;
    ListNode *l2;
    ListNode *l3;
    l1 = new ListNode();
    l2 = new ListNode();
    l3 = new ListNode();
    int arr[10];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    arr[4] = 4;
    arr[5] = 5;
    arr[6] = 6;
    arr[7] = 7;
    arr[8] = 8;
    arr[9] = 9;

    //
    cout<<"Start";
    Solution s1;
    l3 = s1.prefillNode(arr,10);
    //l3 = s1.addTwoNumbers(l1,l2);
    cout << "L3:" << l3; 
}