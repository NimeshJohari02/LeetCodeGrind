/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
//Optimised Swap Vector By QP
class Solution {
public:
    int maxDepth(Node* root) {
        if(root == NULL){
            return 0;
        }
    priority_queue<int>pq;
        pq.push(0);
    for(int i =0 ; i<root->children.size();i++){
            pq.push(maxDepth(root->children[i]));
        }
        return 1+pq.top();
    }
};