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
    vector<int> bottomView(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        queue<pair<TreeNode *, int>> q;
        map<int, int> mp;
        q.push({root, 0});
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            auto [node, level] = front;
            if (node->left)
                q.push({node->left, level - 1});
            if (node->right)
                q.push({node->right, level + 1});
            mp[level] = node->data;
        }
        vector<int> ans;
        for (auto &it : mp)
            ans.push_back(it.second);
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
    auto ans1 = s1->bottomView(root);
    for (auto &it : ans1)
        cout << it << " ";
    return 0;
}