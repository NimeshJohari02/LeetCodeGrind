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
    bool isPalindrome(ListNode* head) {
      ListNode* start=head;
      string s1 ;
      while(start){
        s1+=to_string(start->val);
        start=start->next;
      }
      cout<<s1<<endl;
      for(int i=0;i<=s1.length()/2;i++){
        if(s1[i]!=s1[s1.length()-i-1]){
          return false;
        }
      }
      return true;
      
    }
};