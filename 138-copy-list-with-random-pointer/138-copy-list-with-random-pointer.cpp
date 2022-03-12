/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node* , Node *> mp;
        if(head == NULL)return NULL;
        Node *temp = head;
        while(head != NULL){
            if(mp[head]==NULL){
                mp[head] = new Node(head->val);
            }
            if(!mp[head->next])
            mp[head->next] = head->next != NULL ? new Node(head->next->val) : nullptr;
            
            if(!mp[head->random])
            mp[head->random] = head->random == NULL ? nullptr : new Node(head->random->val);
            
            mp[head]->next = mp[head->next];
            mp[head]->random = mp[head->random];
            head = head->next;
        }
        return mp[temp];
    }
};