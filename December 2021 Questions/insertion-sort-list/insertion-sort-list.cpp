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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *previous = dummy, *curr = head;
        while (curr) {
            if ((curr->next) && (curr->next->val<curr->val)) {
                while ((previous->next) && (previous->next->val < curr->next->val)) {
                    previous = previous->next;
                }
                ListNode* temp = previous->next;
                previous->next = curr->next;
                curr->next = curr -> next -> next;
                previous -> next -> next = temp;
                previous = dummy;
            }
            else {
                curr = curr -> next;
            }
        }
        return dummy -> next;  
    }
};