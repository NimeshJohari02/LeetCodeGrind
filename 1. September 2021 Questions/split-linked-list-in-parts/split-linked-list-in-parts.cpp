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
  int length(ListNode*head){
    if(head == NULL){
      return 0;
    }
    int count =0;
    while(head){
      head=head->next;
      count++;
    }
    return count;
  }
  vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = length(head);
        int groupSize1 = n/k;
        vector<ListNode *>soln;
        int groupSize2 =(n/k)+1;
        int countForSize2=n%k;
        while(countForSize2--){
          int temp=groupSize2;
          ListNode *current = head;
          while(--temp){
            current= current->next;
          }
          ListNode* nextHead =current==NULL?NULL:current->next;
          current->next=NULL;
          soln.push_back(head);
          head = nextHead;
        }
         int countForSize1=(k-(n%k));
      while(countForSize1--){
          int temp=groupSize1;
          if(head==NULL || temp == 0){
            soln.push_back(NULL);
          }else{
          ListNode *current = head;
          while(--temp){
            current= current==NULL?NULL:current->next;
              // temp--;
          }
          ListNode* nextHead =current==NULL?NULL:current->next;
        if(current!=NULL){
            current->next=NULL;
        }
          soln.push_back(head);
          head = nextHead;
        }
      }
         return soln;
    }
};