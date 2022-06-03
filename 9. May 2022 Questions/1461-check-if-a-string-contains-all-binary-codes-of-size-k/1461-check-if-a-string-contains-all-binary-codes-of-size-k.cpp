class Solution {
public:
    // Brute Force Checking the number from 0 to (1<<k)-1 and see if it exist in string 
    // Optimized Approach is to Generate all  Distinct Substrings of Size K add them to the map ;
    // if mp.size() == 1<<k return true;
    unordered_map<string , bool> mp;
    void generateSubStringK(string &s , int k){
        int i=0 , j = 0;
        while(j < s.size()){
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1==k){
                // cout<<"i = "<<i <<"\n";
                string str = s.substr(i  , k);
                // cout<<str<<" \n";
                mp[s.substr(i ,k)] = true;
                j++;
            }
            else{
                while(j-i+1>k){
                    i++; 
                }
            }
        }
        return ;
    }
    bool hasAllCodes(string s, int k) {
        generateSubStringK(s , k);
        cout<<mp.size()<<"  "<<"\n";
        return mp.size()==(1<<k);
        
    }
};