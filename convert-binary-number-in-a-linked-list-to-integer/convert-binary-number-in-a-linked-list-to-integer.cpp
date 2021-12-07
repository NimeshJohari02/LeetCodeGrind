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
    int len(ListNode *head){
        int l =0;
        if(head == NULL)
        {
            return 0;
        }
        while (head){
            head=head->next ;
            l++;
        }
        return l;
    }
    int getDecimalValue(ListNode* head) {
        int l = len(head);
        unsigned ans =0;
        while(head){
            ans+=head->val*pow(2,l-1);
            l--;
            head=head->next;
        }
        return ans;
    }
};
int getDecimalValue(ListNode* head) {
        int num = head->val;
        while(head->next){
            num = num<<1 | head->next->val;
            head=head->next;
        }
        return num;
}
