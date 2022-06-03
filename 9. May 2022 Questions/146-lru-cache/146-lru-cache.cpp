
class LRUCache {
public:
    class Node{
        public :
        int key , value ;
        Node *prev , *next;
        Node(int k, int v){
            key = k ;
            value = v;
        }
    };
    Node *head = new Node(-1 , -1);
    Node *tail = new Node(-1 , -1);
    unordered_map<int , Node*> mp;
    int capacity;
    LRUCache(int c) {
        capacity =  c;
        head->next = tail ;
        tail->prev = head;
    }
    void addNode(Node *&newNode){
        Node *dummy = head->next;
        head->next = newNode;
        newNode ->next = dummy;
        newNode->prev = head;
        dummy->prev = newNode;
    }
    void deleteNode(Node *&delNode){
        Node *prev = delNode->prev ;
        Node *next = delNode ->next;
        prev->next = next;
        next->prev = prev;
    }
    int get(int key) {
        
        if(mp.find(key) != mp.end()){
            Node * ans = mp[key];
            int ansVal = ans->value;
            mp.erase(key);
            deleteNode(ans);
            addNode(ans);
            mp[key] = head->next;
            return ansVal;
        }
        return -1 ;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node *existingNode = mp[key];
            mp.erase(key);
            deleteNode(existingNode);
        }
        if(mp.size() == capacity){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node *newNode = new Node(key , value);
        addNode(newNode);
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */