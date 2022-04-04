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
    void NthEnd(ListNode *&head , int n)
    {
        ListNode *slow = head , *fast = head;
        while(slow != NULL and n--){
            slow = slow -> next;
        }
        ListNode *nFromBegin = slow ;
        // cout<<nFromBegin->val<<"   \n";

        while(slow != NULL && slow->next != NULL){
            slow = slow ->next;
            fast = fast ->next;
        }
        // cout<<fast->val<<"   ";
        swap(fast->val , nFromBegin->val);
        return ;
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL ) return NULL ;
        NthEnd(head, k-1);
        return head;
    }
};