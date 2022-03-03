struct Node {
  Node *links[26];
  bool flag = false;

  bool containsKey(char ch) { return (links[ch - 'a'] != nullptr); }
  Node *get(char ch) { return links[ch - 'a']; }
  void put(char ch, Node *node) { links[ch - 'a'] = node; }
  void setEnd() { flag = true; }
  bool isEnd() { return flag; }
};
class Trie {
private:
  Node *root;

public:
  /** Initialize your data structure here. */
  Trie() { root = new Node(); }

  /** Inserts a word into the trie. */
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

  /** Returns if the word is in the trie. */
  bool search(string word) {
    Node *node = root;
    for (int i = 0; i < word.size(); i++) {
      if (!node->containsKey(word[i])) {
        return false;
      }
      node = node->get(word[i]);
    }
    if (node->isEnd()) {
      return true;
    }
    return false;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    Node *node = root;
    for (int i = 0; i < prefix.size(); i++) {
      if (!node->containsKey(prefix[i])) {
        return false;
      }
      node = node->get(prefix[i]);
    }
    return true;
  }
};

class Solution {
public:
    // difference in word length is by calculating the ascii sum of the words
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool isEndWordPresent = false;
        for(auto&it:wordList)
            if(it==endWord)
                isEndWordPresent=true;
        if(!isEndWordPresent) return 0;
        Trie trie;
        for(auto &it:wordList)
            trie.insert(it);
        unordered_map<string , bool > mp;
        queue<string>q;
        mp[beginWord] = true;
        q.push(beginWord);
        int d =0;
        int n = endWord.size();
        while(!q.empty()){
            d++;
            int curr = q.size();
            while(curr--){
                string front = q.front();
                //cout<<front<<"  \n";
                q.pop();
                for(int i=0 ; i < n ; i++){
                    string temp = front;
                    for(char ch = 'a' ; ch<='z' ; ch++){
                        temp[i] = ch;
                        if(front == temp)
                            continue;
                        if(temp == endWord)
                            return d+1;
                        if(!mp[temp] && trie.search(temp)){
                            q.push(temp);
                            mp[temp] =true;
                        }
                    }
                }
            }
        }
    return 0;
    }
};
