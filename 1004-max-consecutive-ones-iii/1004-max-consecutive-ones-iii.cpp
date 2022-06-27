class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
    int cz = 0 , ans = 0 , i =0 , j =0 ;
    while(j < arr.size()){
        if(arr[j]==0) cz++;
        while(cz>k){
            if(arr[i]==0)cz--;
            i++;
        }
        ans = max(ans , j-i+1);
        j++;
    }
    // cout<<ans<<"\n";
        return ans ;
    }
};