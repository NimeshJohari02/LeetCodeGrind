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
    string reduceToRoot(string &word){
        Node *node = root;
        string ans ="";
        for(int i=0 ; i < word.size() && node ; i++){
            if(!node->containsKey(word[i])){
                return word;
            }
            else{
                ans += word[i];
                node= node->get(word[i]);
                if(node->isEnd() == true) return ans;
            }
        }
        return word;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for(auto &it : dictionary) 
            trie.insert(it);
        string ans;
         string delim = " ";
    vector<string> words{};

    int pos = 0;
    while ((pos = sentence.find(delim)) != string::npos) {
        words.push_back(sentence.substr(0, pos));
        sentence.erase(0, pos + delim.length());
    }
    if (!sentence.empty())
        words.push_back(sentence.substr(0, pos));   
        for(auto&it : words){
            ans+= trie.reduceToRoot(it)+" ";
        }
        ans.pop_back();
        return ans;
    }
};