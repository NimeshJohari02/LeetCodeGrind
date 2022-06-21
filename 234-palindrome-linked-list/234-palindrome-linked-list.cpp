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
    bool bruteForce(ListNode*head){
        string str ;
        while(head) str += (to_string(head->val)) , head=head->next;
        int n = str.size();
        for(int i=0 ;  i<=n/2 ; i++)
            if(str[i] != str[n-i-1]) return false;
        return true;
    }
    bool brute2(ListNode *head){
        stack<ListNode*>stk;
        ListNode *iter = head;
        while(iter) stk.push(iter) , iter=iter->next;
        while(head) {
            if(stk.top()->val != head->val) return false;
            head = head->next;
            stk.pop();
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        // return brute2(head);
        // return bruteForce(head);
        if(head->next == NULL) return true;
        ListNode *slow = head , *fast = head , *prev = NULL , *temp ;
        while(fast && fast->next)
        {
            fast = fast ->next->next;
            // Get the next node before making reversing so as to move front 
            temp = slow->next;
            slow->next = prev;
            prev = slow ;
            slow = temp ;
        }
        slow = fast ? slow->next : slow ;
        while(slow){
            if(slow->val!=prev->val) return false;
            slow = slow->next ;
            prev = prev->next;
        }
        return true;
        }
};