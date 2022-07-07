class Solution {
public:
    int ans =INT_MAX;
    void rec(int idx , int n , vector<int>&ds , int &k , vector<int> &arr){
        if(idx == n ){
            int smallAns = INT_MIN;
            for(auto &it : ds) smallAns = max(smallAns , it);
            ans = min(ans,smallAns);
            return ;
        }
        for(int i =0 ; i < k ; i++){
            ds[i]+=(arr[idx]);
            rec(idx+1 , n , ds , k , arr);
            ds[i]-=arr[idx];
        }
        return ;
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size() ;
        vector<int>ds(k , 0);
         rec(0 , n , ds , k , cookies);
        return ans;
    }
};