class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int>ans(ratings.size() ,1 );
        for(int i=1 ; i< ratings.size() ; i++)
            if(ratings[i] > ratings[i-1])
                ans[i] = 1+ans[i-1];
        for(int i=ratings.size()-1 ; i>0 ; i--)
            if(ratings[i-1]>ratings[i])
			     ans[i-1]=max(ans[i]+1,ans[i-1]);
        int sum =0;
        for(auto &it : ans) sum+=it;
        return sum;
    }
};