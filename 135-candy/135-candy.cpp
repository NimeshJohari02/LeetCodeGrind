class Solution {
public:
    int candy(vector<int>& rating) {
        int n = rating.size();
        vector<int>dist(n , 1);
        for(int i=1 ; i < n ;i++)
            if(rating[i] > rating[i-1])
                dist[i] = 1 + dist[i-1];
        for(int i =n-1 ; i>0 ; i--)
            if(rating[i-1] > rating[i])
                dist[i-1] = max(dist[i] +1 , dist[i-1]);
    int sum = accumulate(dist.begin() , dist.end() , 0);
        return sum;
    }
};