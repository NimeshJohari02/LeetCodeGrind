/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head , Node *remaining=NULL){
        // if(head == NULL)
        // {
        //     return head;
        // }
        // Node *rc = NULL;
        //  Node *pr = head;
        // if(head->child != NULL)
        //  { 
        //     rc = flatten(head->child);
        //     rc->prev=head;
        //     head->child=NULL;
        // }
        // head->next = rc!=NULL ? rc : flatten(head->next);    
        // Node *temp = rc ;
        // while(temp and temp->next){
        //     temp=temp->next;
        // }
        // if(temp and temp->next){
        // temp->next = pr->next;
        // }
        // return head;
        
        
        if (head == NULL){
            return remaining;
        }
        
        head->next = flatten(head->child , flatten(head->next , remaining));
        if(head -> next){
            head->next->prev = head;
        }
        head->child=NULL;
        return head;
    }
};