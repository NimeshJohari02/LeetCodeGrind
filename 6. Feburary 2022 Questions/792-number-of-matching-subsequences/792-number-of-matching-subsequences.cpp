// struct Node {
//   Node *links[26];
//   bool flag = false;

//   bool containsKey(char ch) { return (links[ch - 'a'] != nullptr); }
//   Node *get(char ch) { return links[ch - 'a']; }
//   void put(char ch, Node *node) { links[ch - 'a'] = node; }
//   void setEnd() { flag = true; }
//   Node* next(){
//       for(int i=0 ; i < 26 ; i++)
//           if(links[i]!= NULL)return links[i];
//       return NULL;
//     }
//   bool isEnd() { return flag; }
// };
// class Trie {
//  private:
//   Node *root;

//  public:
//   /** Initialize your data structure here. */
//   Trie() { root = new Node(); }

//   /** Inserts a word into the trie. */
//   void insert(string word) {
//     Node *node = root;
//     for (int i = 0; i < word.size(); i++) {
//       if (!node->containsKey(word[i])) {
//         node->put(word[i], new Node());
//       }
//       node = node->get(word[i]);
//     }
//     node->setEnd();
//   }
//     int dummyInsert(string str ){
//         Node *node = root;
//         int ctr=0;
//         int i=0;
//        while(i < str.size()){
//         if(node==NULL) break;
//             if(node->containsKey(str[i])){
//                 ctr++;
//                node =  node ->get(str[i]);
//                 i++;
//             }
//             else{
//                 node = node->next();
//                 }
//             }
//         if(str.size() == ctr){
//             cout<<str<<"   ";
//         }
//         return (str.size() == ctr)? 1 : 0 ;    
//     }
// };

class Solution {
public:
//     int numMatchingSubseq(string s, vector<string>& words) {
// //         Trie trie;
// //         trie.insert(s);
// //         int ans =0;
// //         for(auto &it : words)
// //             ans+=trie.dummyInsert( it);
        
//     return ans;
//     }
     int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> pos[26]; 
        int n = s.size(); 
        int res = 0; 
        for(int i = 0; i < n; i++) {
            pos[s[i]-'a'].push_back(i);
        }
        
        for(auto &word : words) {
            int x = -1; 
            bool found = true; 
            
            for(auto &ch : word) {
                auto it = upper_bound(pos[ch-'a'].begin(), pos[ch-'a'].end(), x);
                if(it == pos[ch-'a'].end()) found = false; 
                else x = *it; 
            }
            
            if(found) res++;
        }
        return res; 
    }
};