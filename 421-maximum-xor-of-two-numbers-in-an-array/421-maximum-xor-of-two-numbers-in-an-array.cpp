struct Node{
    Node *links[2];
    bool containsKey(int idx){
        return links[idx] != NULL;
    }
    Node *get(int idx){
        return links[idx];
    }
    void put(int idx , Node *node){
        links[idx] = node;
    }
};
class Trie{
    private : 
    Node *root;
    public :
    Trie(){
        root = new Node();
    }
    void insert(int n){
        Node *node = root;
        for(int i = 31 ; i>=0 ; i--){
            int ithBit = (n >> i) &1;
            if(!node->containsKey(ithBit))
                node->put(ithBit , new Node());
            node = node->get(ithBit);
        }
    }
    int getMaxFromNumber(int number){
        Node *node = root;
        int maxNum =0;
        for(int i=31 ; i>=0 ; i--){
            int ithNumBit = (number>>i) & 1;
            if(node->containsKey(1-ithNumBit)){
                maxNum = maxNum | 1<<i;
                node = node->get(1-ithNumBit);
            }
            else{
                node = node->get(ithNumBit);
            }
        }
        return maxNum;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
     Trie trie; 
        for(auto &it : nums)
            trie.insert(it);
        int maxi = 0;
        for(auto&it:nums){
            maxi = max(maxi , trie.getMaxFromNumber(it));
        }
        return maxi;
    }
};