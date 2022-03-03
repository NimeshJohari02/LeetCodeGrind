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
// I need to make 2 sorts of connections Nodes With Same Parent  and Nodes with Different Parent 

class Solution {
public:
    Node* connectWithSameParent(Node* root){
        if(root == NULL){
            return NULL;
        }
        if(root->left != NULL and root->right != NULL){
            root->left->next = root->right;
        }
        root->left = connectWithSameParent(root->left);
        root->right = connectWithSameParent(root->right);
        return root;
    }
    Node* connectWithDifferentParent(Node *root){
        if(root == NULL){
            return NULL;
        }
        if(root->right != NULL and root->next != NULL){
            root->right->next = root->next->left;
        }
        root->right =connectWithDifferentParent(root->right);
        root->left =connectWithDifferentParent(root->left);
        return root;
    }
    Node* connect(Node* root) {
        if(root== NULL){
            return NULL;
        }
        Node* modifiedRoot = connectWithSameParent(root);
        return connectWithDifferentParent(modifiedRoot);
    }
};

// 12 ms Approach from the solutions 




class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        if(root->left){
            root->left->next = root->right;
            if(root->next){
                root->right->next = root->next->left;
            }
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};



