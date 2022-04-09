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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if(a == NULL) return b ;
        if(b== NULL ) return a;
        ListNode *c = new ListNode();
        if(a->val >= b->val){
            c->val = b->val;
            c->next = mergeTwoLists(a , b->next);
        }
        else{
            c->val = a->val;
            c->next = mergeTwoLists(a->next , b );
        }
        return c ;
    }
};