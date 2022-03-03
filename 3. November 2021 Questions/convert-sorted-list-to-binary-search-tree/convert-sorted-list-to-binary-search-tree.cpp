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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    // Approach is similar to make BST From Sorted Array . Just Instead Of finding the mid in O(1) we have to use slow and fast pointers
public:
    TreeNode* helper(ListNode *head , ListNode *tail){
        if(head == tail){
            return NULL;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast!=tail and fast->next != tail){
            fast = fast->next->next;
            slow=slow->next;
        }
        TreeNode *root = new TreeNode(slow->val,helper(head , slow), helper(slow->next , tail));
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        TreeNode *root = helper(head , NULL );
        return root;
    }
};

