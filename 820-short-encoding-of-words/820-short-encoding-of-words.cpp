// struct Node{
//     Node *links[26];
//     bool isEnd = false;
//     bool containsKey(char ch){return links[ch-'a'] != NULL;}
//     Node* get(char ch){return links[ch-'a'];}
//     void put(char ch , Node *node){
//         links[ch-'a'] = node;
//     }
//     bool isWord(){return isEnd;}
//     void setEnd(){isEnd = true;}
// };
// class Trie{
//     private : 
//     Node *root ;
//     public :
//     Trie(){}
//     void insert(string &word){
//         Node* node = root ;
//         for(auto &it : word){
//             if(!node->containsKey(it))
//                 node->put(it, new Node());
//             node = node->get(it);
//         }
//         node->setEnd();
//         return ;
//     }
// };
// We have to find the largest suffix which can be done using sort and reversing(to make suffix come first);
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for(auto &it : words)reverse(it.begin()  , it.end());
        sort(words.begin() , words.end()) ;
        int len = 0 , n = words.size();
        for(int i=0 ; i < n; i++){
            while(i+1 < n  && words[i+1].substr(0 , words[i].size()) == words[i])i++;
            len += words[i].size()+1;
        }
        return len;
    }
};