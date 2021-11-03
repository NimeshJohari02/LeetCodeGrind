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
    void deleteNode(ListNode* node) {
        ListNode *node_next = node->next;
        ListNode *prev=NULL;
        while(node->next){
            node->val=node_next->val;
            node_next=node_next->next;
            prev=node;
            node=node->next;
        }
        prev->next=NULL;
        delete node;
   }
};