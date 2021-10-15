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
    int length(ListNode *root){
        if(root == NULL){
            return 0;
        }
        int cnt =0;
    while(root){
        cnt++;
        root=root->next;
    }
        return cnt;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return head;
        }
        int l = length(head);
        ListNode *temp = head;
        int trav = l-n-1;
        cout<<"TRAV"<<trav<<endl;
        if(trav==-1){
            return temp->next?temp->next:NULL;
        }
        while(head->next && trav>0){
            head=head->next;
            trav--;
        }
        if(head->next!=NULL){
        if(head->next->next){
            head ->next = head->next->next;
        }
        else{
            head->next=NULL;
        }
        }
        return temp;
    }
};