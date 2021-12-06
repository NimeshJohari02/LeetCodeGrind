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
 ListNode* reverse(ListNode *headNode){
        if(headNode == NULL){
            return headNode;
        }
            if(headNode->next==NULL or headNode == NULL){
                return headNode;
        }
        ListNode *miniHead = reverse(headNode->next);
        headNode->next->next=headNode;
        headNode->next=NULL;
        return miniHead;
    }
    vector<int> nextLargerNodes(ListNode* head) {
      stack<ListNode *>stk;
        vector<int>ans;
        ListNode *newHead = reverse(head);
        while(newHead != NULL){
            cout<<newHead->val<<"   ";
            while(!stk.empty()){
                if(stk.top()->val > newHead->val) break;
                stk.pop();
            }
            ans.push_back(stk.empty()?0 : stk.top()->val);
            stk.push(newHead);
            newHead = newHead->next;
        }
        std::reverse(ans.begin() , ans.end());
        return ans;
    }
};