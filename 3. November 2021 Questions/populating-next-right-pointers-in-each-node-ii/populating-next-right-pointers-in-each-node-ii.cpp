/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
  Node* connect(Node* root) {
        helper(root);
        return root;
    }
    void helper(Node *root) {
        if (!root) return;
        Node temp(INT_MIN, NULL, NULL, NULL);
        for (Node *cur = root, *pre = &temp; cur; cur = cur->next) {
            if (cur->left) {
                pre->next = cur->left;
                pre = pre->next;
            }
            if (cur->right) {
                pre->next = cur->right;
                pre = pre->next;
            }
        }
        helper(temp.next);
    }

};
