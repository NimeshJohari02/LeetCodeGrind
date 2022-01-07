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
    int LengthOfList = 0;
    ListNode *globalHead = NULL;
    ListNode *temp = NULL;
public:
    int length(ListNode* head){
        int ans =0;
        if(head == NULL)return 0;
        while(head){
            ans++;
            head=head->next;
        }
        return ans;
    }
    Solution(ListNode* head) {
        globalHead = head;
        temp = head;
        LengthOfList = length(head);
    
    }
    
    int getRandom() {
        //cout<<"LL L = "<<LengthOfList<<endl;
        int randomNumber = rand() % ( LengthOfList  );
        //cout<<randomNumber<<"\n";
        while(randomNumber-- and temp != NULL){
            temp = temp->next;
        }
        int val = temp->val;
        temp = globalHead;
        return val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */