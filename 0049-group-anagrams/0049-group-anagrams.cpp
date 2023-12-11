class Solution {
public:
    void processWord(string &str , map<string , vector<string>>&mp){
        int arr[26]={0};
        for(auto &ch : str){
            arr[ch-'a']++;
        }
        // cout<<"FOR STRING STR"<<"  "<<str;
        string sortedWord="" ;
        for(int i=0 ; i <26;i++) sortedWord+=(char)(arr[i]+'a');
         cout<<sortedWord<<"    \n";
        mp[sortedWord].push_back(str);
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // for anagram use a hashmap 
        map<string , vector<string>> mp ;
        // maintain wordCount in sortedOrder 
        
        for(auto &it : strs){
            //map to aabbcc format and push original word in map ;
            processWord(it , mp);
        }
        vector<vector<string>>ans;
        // map has now all anagrams ;
        for(auto &it : mp)
            ans.push_back(it.second);
        return ans;
    }
};
