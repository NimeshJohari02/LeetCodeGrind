
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
    void DFSTraversal(TreeNode *root, map<int, int> &mp, int level)
    {
        if (root == nullptr)
            return;
        if (mp[level] == 0)
            mp[level] = root->data;
        DFSTraversal(root->left, mp, level - 1);
        DFSTraversal(root->right, mp, level + 1);
        return;
    }

public:
    vector<int> topView(TreeNode *root)
    {
        vector<int> ans;
        map<int, int> mp;
        DFSTraversal(root, mp, 0);
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
    auto ans = s1->topView(root);
    for (auto &it : ans)
        cout << it << " ";
    return 0;
}