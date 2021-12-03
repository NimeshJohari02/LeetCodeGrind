class Solution {
public:
    bool isVowel(char ch){
        return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
    }
    int countVowelSubstrings(string word) {
        int cnt =0;
        for(int i =0 ; i < word.size() ; i++){
        set<char>stk;            
        for(int j =i ; j < word.size() ; j++){
            if(!isVowel(word[j])) break;
            if(isVowel(word[j])){
                stk.insert(word[j]);
                if(stk.size()==5)cnt++;
            }
        }
        }
        return cnt;
    }
};