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
private:
    bool isLeaf(TreeNode *root)
    {
        return !root->left && !root->right;
    }
    void addLeftBoundary(TreeNode *root, vector<int> &res)
    {
        TreeNode *curr = root->left;
        while (curr)
        {
            if (!isLeaf(curr))
            {
                // cout << curr->data << "Adding Curr inside res"
                // << "\n";
                res.push_back(curr->data);
            }
            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }
    void addRightBoundary(TreeNode *root, vector<int> &res)
    {
        TreeNode *curr = root->right;
        stack<int> stk;
        while (curr)
        {
            if (!isLeaf(curr))
                stk.push(curr->data);
            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }
        while (!stk.empty())
        {
            res.push_back(stk.top());
            stk.pop();
        }
        return;
    }
    void addLeaves(TreeNode *root, vector<int> &res)
    {
        if (isLeaf(root))
        {
            res.push_back(root->data);
            return;
        }
        if (root->left)
            addLeaves(root->left, res);
        if (root->right)
            addLeaves(root->right, res);
        return;
    }

public:
    void helper(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
            return;
        helper(root->left, ans);
        ans.push_back(root->data);
        helper(root->right, ans);
        return;
    }

    vector<int> inOrder(TreeNode *root)
    {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
    vector<int> printBoundary(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
            return res;
        if (!isLeaf(root))
            res.push_back(root->data);
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        return res;
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
    auto ans = s1->inOrder(root);
    for (auto &it : ans)
        cout << it << " ";
    cout << '\n';
    auto ans1 = s1->printBoundary(root);
    for (auto &it : ans1)
        cout << it << " ";
    return 0;
}