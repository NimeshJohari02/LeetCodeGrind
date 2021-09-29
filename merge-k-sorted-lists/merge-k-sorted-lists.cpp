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
    ListNode* mergeLL(ListNode *l1 , ListNode *l2){
        if (l1 == NULL) return l2; 
        if (l2 == NULL) return l1;
        if(l1->val > l2->val) {
            l2->next = mergeLL(l1, l2->next);
            return l2;
        }
        else{
            l1->next = mergeLL(l1->next, l2);
            return l1; 
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      ListNode *finalHead=NULL;  
      for(int i=0;i<lists.size();i++){
        finalHead=mergeLL(lists[i],finalHead);
      }
    return finalHead;
    }
};