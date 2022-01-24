class Solution {
public:
    string getPermutation(int n, int k) {
        int fact =1 ;
        vector<int>number ;
        for(int i=1 ; i < n ; i++){
            fact = fact * i;
            number.push_back(i);
        }
        number.push_back(n);
        string ans;
        // To reduce k so as to accomodate 0 based indexing and 1 based indexing asked in the question 
        k--;
        while(true){
            ans = ans + to_string(number[k / fact]);
            number.erase(number.begin() + k / fact);
            if(number.size() ==0)break;
            k = k % fact;
            fact = fact / number.size();
        }
        return ans;
    }
};


/*
BRUTE FORCE SOULTION GIVES TLE !!! THUS OPTIMIZE 
class Solution {
    private : 
    vector<string> ans;
     void getPermutation(string str , int i=0){
        if(i==str.size()-1){
            ans.push_back(str);
            return ;
        }
        for(int j=i;j<str.size();j++){
            // here we run from j =idx or i till size because we have to swap with aage ke elements
            swap(str[i],str[j]);
            getPermutation(str,i+1);
            //Backtrack
            swap(str[i],str[j]);
        }
    return;
     }
    
public:
    // Brute Force -> Use Recursion Generate All Permutations and Sort and return ;
    string getPermutation(int n, int k) {
        string str ;
        for(int i=1 ; i<=n;i++)
            str+=to_string(i);
        getPermutation(str , 0);
        sort(ans.begin() , ans.end());
        return ans[k-1];
    }
};
*/