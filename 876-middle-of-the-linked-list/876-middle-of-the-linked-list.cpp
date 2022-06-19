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
    int len(ListNode *node){
        int ans = 0 ;
        if(node == NULL) return 0 ;
        while(node!=nullptr){ans++ ; node= node->next;}
        return ans;
    }
    ListNode *bruteForce(ListNode *node){
        int l = len(node);
        l = ceil(l/2);
        while(node != nullptr && l--)node = node->next;
        return node;
    }
    ListNode *slowFast(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != NULL && fast ->next != NULL)
            slow = slow->next , fast = fast->next->next;
        return slow;
    }

    ListNode* middleNode(ListNode* head) {
        return slowFast(head);
    }
};