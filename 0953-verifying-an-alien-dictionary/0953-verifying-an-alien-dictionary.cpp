class Solution {
public:
    bool checkWordOrdering(string word1 , string word2 , unordered_map<char , int>&mp){
        int i=0 , j =0 ;
        while(i < word1.size() && j < word2.size()){
            if(word1[i]==word2[j])
                i++,j++;
            else{
                // if they follow order ok else return false 
                if(mp[word1[i]]>mp[word2[j]])return false ;
                return true ;
            }
        }
        if(i < word1.size())return false; // Phi Case ..
        return true ;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char , int>mp ;
        for(int i=0 ; i < order.size(); i++)mp[order[i]] = i ;
        for(int i=0 ; i < words.size()-1 ; i++){
            if(checkWordOrdering(words[i], words[i+1] , mp) == false) return false ;
        }
        return true ;
    }
};