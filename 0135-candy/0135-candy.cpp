class Solution {
public:
    int candy(vector<int>& rating) {
        int n = rating.size() ;
        vector<int>ans(n , 1);
        // it should have more candies than one of the left 
        for(int i = 1 ; i < n; i++)
            if(rating[i]>rating[i-1])
                ans[i] = 1+ans[i-1];
        //right trav;
        //102
        
        for(int i=n-1; i>0;i--){
            if(rating[i-1]>rating[i])
                ans[i-1] =max(ans[i-1] , 1+ans[i]);
        }
        
        int sum = 0;
        for(auto &it : ans)cout<<it<<"  ";
        cout<<endl;
        for(auto &it : ans)sum+=it;
        return sum ; 
    }
};