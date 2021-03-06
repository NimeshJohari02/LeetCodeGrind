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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        if(head->next == NULL)
            return head;
        ListNode *fast = head->next;
    while(fast && fast->next){
        fast = fast->next->next;
        slow=slow->next;
    }
        if(fast == NULL)
        return slow;
        if(fast->next == NULL)
            return slow->next;
        return NULL;
    }
};