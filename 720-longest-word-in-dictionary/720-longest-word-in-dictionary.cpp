struct Node{
    Node*links[26];
    bool flag= false;
    Node*get (char ch) {return links[ch-'a'];}
    void put(char ch , Node*node){links[ch-'a']=node; }
    bool containsKey(char ch){return links[ch-'a']!=NULL;}
    void setEnd(){flag = true;}
    bool isEnd(){return flag;}
};
class Trie{
    private:
    Node *root;
    public :
    Trie(){root = new Node();}
  void insert(string word) {
    Node *node = root;
    for (int i = 0; i < word.size(); i++) {
      if (!node->containsKey(word[i])) {
        node->put(word[i], new Node());
      }
      node = node->get(word[i]);
    }
    node->setEnd();
  }
   bool isLongestWord(string word){
        Node* node = root;
        
        for(char& ch : word){
            if(node == root || node->isEnd()){
                node = node->get(ch);
                continue;
            }
            return false;
        }
        
        return true;
    }
};
class Solution {
    
public:
    static bool cmp(string &s1 , string &s2){
        return s1.length()>s2.length();
    }
    string longestWord(vector<string>& words) {
        Trie trie;
        string ans ="";
        int size =0;
        for(string& str : words)
            trie.insert(str);
        for(string& str : words){
            if(trie.isLongestWord(str) && size <= str.size()){
                ans = (size == str.size()) ? min(ans, str) : str;
                size = str.size();
            }
        }
        return ans;
    }
};