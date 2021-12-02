/**
 * Definition for singly-linked list.
 * struct LisListNode {
 *     int val;
 *     ListListNode *next;
 *     ListListNode() : val(0), next(nullptr) {}
 *     ListListNode(int x) : val(x), next(nullptr) {}
 *     ListListNode(int x, ListListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return NULL;
             ListNode *odd= head;
        ListNode *even = head->next;
        ListNode* evenStart=even;
        while(odd->next and even->next){
                odd->next=even->next;
                odd=odd->next;
                even->next=odd->next;
                even=even->next;
        }
        odd->next=evenStart;
        if(odd->next!=NULL and even!= NULL ){
                even->next=NULL;
        }
    
    return head;
    }
    
};