class Solution {
public:
    string getPermutation(int n, int k) {
       long long int fact =1 ;
        vector<int>nums(n);
        for(int i=1 ; i<n ; i++)
            fact *=i;
        iota(nums.begin() , nums.end() , 1);
        // iota is used to create the nums -> 1 2 3 4 ... so on :)
        k--;
        string ans = "";
        while(true){
            ans += to_string(nums[k / fact]);
            nums.erase(nums.begin() + k / fact);
            if(nums.size() ==0 )
                break;
            k %= fact;
            fact /= nums.size();
        }
        return ans;
    }
};