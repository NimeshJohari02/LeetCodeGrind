/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL)return NULL;
        map<Node* , Node* > mp;
        queue<Node *>q;
        q.push(node);
        mp[node] = new Node(node->val);
        while(!q.empty()){
            int k = q.size();
            for(int i=0 ; i < k ; i++){
                Node *currNode = q.front();
                q.pop();
                for(auto&it : currNode->neighbors){
                    if(mp[it]==NULL){
                        mp[it] = new Node(it->val);
                        q.push(it);
                    }
                    mp[currNode]->neighbors.push_back(mp[it]);
                }
            }
        }
        return mp[node];
    }
};