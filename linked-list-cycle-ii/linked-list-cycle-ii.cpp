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
    ListNode *detectCycle(ListNode *head) {
        if(head ==  NULL or head->next == NULL){
            return NULL;
        }
        ListNode *slow = head;
        ListNode *fast = slow;
        while(fast->next!=NULL and fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast){
                 while(slow != head) 
                 {               
                slow  = slow->next;
                head = head->next;
            }
            return head;                
            }

        }
        return NULL;
    }
};