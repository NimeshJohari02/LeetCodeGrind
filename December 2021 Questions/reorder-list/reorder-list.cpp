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
    void reorderList(ListNode* head) {
        stack<ListNode*>stk;
        ListNode * slow = head ;
        ListNode *fast = head->next!=NULL ? head->next : NULL;
        while(fast != NULL and fast->next!=NULL){
            slow = slow->next ;
            fast = fast->next->next;
        }
        stk.push(NULL);
        ListNode *prevSlow = slow;
        while(slow != NULL){
            stk.push(slow);
            slow = slow->next ;
            }
        
        while(!stk.empty() && head!=NULL and head->next){
            ListNode *nodeToInsert = stk.top();
            stk.pop();
            ListNode* nextNode = head->next!=NULL ? head->next : NULL;
            head->next = nodeToInsert;
            if(nodeToInsert!=NULL)
            nodeToInsert->next = nextNode;
            if(head->next!=NULL && head!= NULL)
            head=head->next->next;
        }
        
    }
};