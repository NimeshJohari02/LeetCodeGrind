class Solution {
public:
    vector<int>power;
    int prime = 10000007;
    string rabinKarp(string mainString , int currlen){
        if(currlen==0){
            return "";
        }
        unordered_map<int,vector<int>>hashmap;
        int hash=0;
        for(int i=0;i<currlen;i++){
            hash= (hash*26+(mainString[i]-'a'))%prime;
        }
        hashmap[hash]={0};
        for(int i=currlen ; i<mainString.size();i++){
         hash = ((hash - power[currlen-1] * (mainString[i-currlen]-'a')) % prime + prime) % prime;
         hash = (hash * 26 + (mainString[i]-'a')) % prime;    
            if(hashmap.find(hash) == hashmap.end())   hashmap[hash ] = {i-currlen+1};
            else {
             // this is for the part when they match and we have to check the exact string
                for(int start: hashmap[hash]) {
                    if(mainString.substr(start, currlen) == mainString.substr(i-currlen+1, currlen)) 
                    {  
                        return mainString.substr(start, currlen); 
                    }
                }
                hashmap[hash].push_back({i-currlen+1});
            }
        }
        return "";    
    }
    string longestDupSubstring(string s) {
        int l =1 ;
        power = vector<int>(s.length());
        for(int i =0; i<s.length();i++){
            power[i]=((i==0)?1:(power[i-1]*26)%prime);
        }
        int r = s.length()-1;
        string ans ="";
        while(r>=l){
            int mid = l + (r - l) / 2;
             string str2= rabinKarp(s , mid);
            if(ans.size()<str2.size()){
                ans = str2;
                l = mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;      
    }
};