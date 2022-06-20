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
    ListNode* iterative(ListNode *list1 , ListNode* list2){
        ListNode *dummyHead = new ListNode(INT_MAX);
        ListNode *ans = dummyHead;
        while(list1!=nullptr && list2!=nullptr){
            // ListNode *newNode = new ListNode();
            if(list1->val < list2->val) 
            {
                dummyHead->next = list1;
                list1=list1->next;
            }
            else{
                dummyHead->next = list2;
                list2=list2->next;
            }
            dummyHead=dummyHead->next;
        }
        if(list1!=nullptr)dummyHead->next = list1;
        else dummyHead->next = list2;
        return ans->next;
    }
    ListNode *rec(ListNode *a , ListNode *b){
        if(a==nullptr && b==nullptr) return nullptr;
        if(a==nullptr && b!= nullptr) return b;
        if(a!=nullptr && b == nullptr) return a ;
        ListNode *c = new ListNode();
        if(a->val > b ->val){
            c->val = b->val;
            c->next= rec(a , b->next);
        }
        else {
            c->val = a->val;
            c->next = rec(a->next,b);
        }
        return c;
    }
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        // return iterative(list1 , list2);
        return rec(a , b);
    }
};