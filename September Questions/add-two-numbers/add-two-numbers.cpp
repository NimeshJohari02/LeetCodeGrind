/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
    void insert(ListNode*& headNode, int data){
      if(headNode== NULL){
        headNode =new ListNode(data);
        return ;
      }
      ListNode* temp = headNode;
      while(temp->next){
        temp=temp->next;
      }
      ListNode *d =new ListNode(data);
      temp->next=d;
      return;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      bool carry = false;
      ListNode *head= NULL;
      while(l1!=NULL and l2 !=NULL){
        int d = l1->val+l2->val+(carry?1:0);
        carry=false;
        if(d>=10){
          carry = true;
          d=d-10;
        }
        insert(head,d);
        l1=l1->next;
        l2=l2->next;
      }
      while(l1){
        int d = l1->val+(carry?1:0);
        carry=false;
        if(d>=10){
          carry = true;
          d=d-10;
        }
          insert(head,d);
          l1=l1->next;
      } 
      while(l2){
        int d = l2->val+(carry?1:0);
        carry=false;
        if(d>=10){
          carry = true;
          d=d-10;
        }
          insert(head,d);
          l2=l2->next;
      }
      if(carry){
        insert(head,1);
      }
      return head;
    }
};