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
    ListNode* doubleIt(ListNode* head) {
        stack<ListNode *> stk ;
        ListNode *temp = head ;
        while(temp != nullptr){
            stk.push(temp);
            temp = temp->next ;
        }
        int carry =0 ;
        while(!stk.empty()){
            auto node = stk.top();
            stk.pop();
            int val = node->val *2 + carry  ;
            if(val >=10){
                node->val = val-10 ;
                carry = 1 ;
            }
            else{
                node->val = val;
                carry = 0 ;
            }
        }
        ListNode* newNode=nullptr;
        if(carry > 0){
        newNode = new ListNode(carry);
            newNode->next = head ;
        }
        return carry >0 ? newNode : head;
      }
};