/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    long long int getLength(ListNode* head){
      long long int count =0;
      while(head){
        count++;
        head=head->next;
      }
      return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      long long int l1 = getLength(headA);
      long long int l2 = getLength(headB);
      ListNode *ptr1,*ptr2;
      if(l1>l2){
        ptr1=headA;
        ptr2=headB;
      }
      else{
        ptr1=headB;
        ptr2=headA;
      }
      long long int d = labs(l2-l1);
      while(d-- and ptr1){
        ptr1=ptr1->next;
      }
      while(ptr1!=NULL and ptr2!=NULL){
        if(ptr1 == ptr2){
          return ptr1;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
      }
      return NULL;
      }
};