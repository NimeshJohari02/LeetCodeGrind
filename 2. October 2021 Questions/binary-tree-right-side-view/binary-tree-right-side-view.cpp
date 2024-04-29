#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode(int val)
    {
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};
class Solution
{
public:
    void DFS(TreeNode *root, vector<int> &ans, int currHeight)
    {
        if (root == nullptr)
            return;
        if (currHeight == ans.size())
        {
            ans.push_back(root->data);
        }
        DFS(root->right, ans, currHeight + 1);
        DFS(root->left, ans, currHeight + 1);
        return;
    }
    vector<int> rightView(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        vector<int> ans;
        int currentHt = 0;
        DFS(root, ans, currentHt);
        return ans;
    }
};
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(4);
    root->left->left->right->left = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);
    root->right->right->left->left = new TreeNode(10);
    root->right->right->left->right = new TreeNode(11);
    Solution *s1 = new Solution();
    auto ans1 = s1->rightView(root);
    for (auto &it : ans1)
        cout << it << " ";
    return 0;
}