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
public:
    vector<int>arr1;
    vector<int>arr2;
    void getSortedArray(TreeNode *root, vector<int>&arr){
        if(root==NULL)
            return;
        getSortedArray(root->left, arr);
        arr.push_back(root->val);
        getSortedArray(root->right , arr);
        return;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
     getSortedArray(root1,arr1);
     getSortedArray(root2,arr2);
        vector<int>ans(arr1.size()+arr2.size(),0);
        int i =0,j=0,k=0;
        while(i<arr1.size() && j<arr2.size()){
            if(arr1[i]>=arr2[j]){
                ans[k++]=arr2[j++];
            }
            else{
                ans[k++]=arr1[i++];
            }
        }
        while(i<arr1.size()){
            ans[k++]=arr1[i++];
        }
        while(j<arr2.size()){
            ans[k++]=arr2[j++];
        }
        return ans;
    }
};