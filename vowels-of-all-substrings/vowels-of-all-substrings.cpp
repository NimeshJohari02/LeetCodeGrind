class Solution {
public:
        bool isVowel(char ch){
        return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
        }
    long long countVowels(string word) {
        long long int finalAns=0;
        for(long long int i =0 ; i < word.length();i++){
            if(isVowel(word[i])){
                finalAns+=(i+1)*(word.length()-i);
            }
        }

        return finalAns;        
    }
};