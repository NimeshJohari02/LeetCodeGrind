struct Node {
    Node *links[26];
    bool flag = false;
    bool isEnd(){return flag;}
    void put(char ch , Node *node){
        links[ch-'a'] = node;
    }
    Node* get( char ch){
        return links[ch - 'a'];
    }
    Node* getIntLink(int idx){
        return links[idx];
    }
    void setEnd(){
        flag=true;
    }
    bool containsKey(char ch ){
        return links[ch-'a'] != NULL;
    }
};
class WordDictionary {
    private :
    Node *root;
    public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node *node = root;
        for(auto &ch : word){
            if(!node->containsKey(ch)){
                node->put(ch , new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    bool helper(string word ,Node *node){
        for(int i=0; i < word.size() && node; i++){
            if(word[i]!='.'){
                if(!node->containsKey(word[i]))return false;
                node=node->get(word[i]);
            }
            else{
                bool found = false;
                int j =0;
                for(; j <26 ; j++){
                if(node->getIntLink(j)) found |= helper(word.substr(i + 1), node->getIntLink(j));
                    if(found) return true;
                }
        if(j == 26) return false;                
            }
        }
        return node->isEnd();
    }
    bool search(string word , int idx = 0 ) {
     Node *node = root;
     return helper(word ,node);
        
    }
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */



class WordDictionary {
public:
    WordDictionary() {}
    
    void addWord(string word) {
        words[word.size()].push_back(word);
    }
    
    bool search(string word) {
        for(auto s: words[word.size()]) if(isEqual(s, word)) return true;
        return false;
    }
    
private:
    unordered_map<int, vector<string>>words;
    
    bool isEqual(string a, string b){
        for(int i = 0; i < a.size(); i++){
            if(b[i] == '.') continue;
            if(a[i] != b[i]) return false;
        }
        return true;
    }
};


