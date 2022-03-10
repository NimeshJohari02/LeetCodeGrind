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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy, *temp;
        dummy = new ListNode();
        temp = dummy;
        int carry = 0;
        while(l1 || l2){
            int x, y, sum;
            x = (l1) ? l1->val : 0;
            y = (l2) ? l2->val : 0;
            l1 = (l1) ? l1->next : nullptr;
            l2 = (l2) ? l2->next : nullptr;
            sum = x + y + carry;
            carry = sum / 10;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }
        if(carry > 0)
            temp->next = new ListNode(carry);
        return dummy->next;
    }
};