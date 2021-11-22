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
    int length(ListNode *head){
        int l =0;
        if (head == NULL){
            return 0;
        }
        while(head){
            l++;
            head = head->next;
        }
        return l;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL){
            return NULL;
        }
        int l = length(head);
        if(l>0){
            k%=l;
        }
        if(l==1 || k==0){
            return head;
        }
        
        ListNode *newHead = head;
        ListNode *newTail = head;
        ListNode *tail = head;
        int move = l-k;
        while(move--){
            newHead=newHead->next;
        }
        while(tail->next){
            tail=tail->next;
        }
        tail->next=head;
        while(newTail->next != newHead){
            newTail=newTail->next;
        }
        newTail->next = NULL;
        return newHead;
        
    }
};