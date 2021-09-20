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
    bool hasCycle(ListNode *head) {
          if(head == NULL || head->next == NULL) { return false; }
    struct ListNode * slow = new ListNode(0);
    struct ListNode * fast = new ListNode(0);
    slow = head;
    fast = slow->next;
    while(slow != fast){
        if(fast == NULL || fast->next == NULL) { return false; }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}
};