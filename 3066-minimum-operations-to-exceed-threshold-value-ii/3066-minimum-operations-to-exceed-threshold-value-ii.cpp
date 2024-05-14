class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long , vector<long long> , greater<long long>>pq;
        for(auto &it : nums)pq.push(it);
        int ans =0 ;
        while(true){
            auto num1  = pq.top();
            // cout << "Num 1 "<< num1 <<"\n";
            pq.pop();
            // cout<< "Pq size "<<pq.size() <<"\n";
            if(pq.size()>=1){
                auto num2 = pq.top();
                pq.pop();
                if(num1>=k) break;
                    else {
                        long long  num = (min(num1, num2)*2LL) + max(num1 , num2);
                        pq.push(num);
                        ans++;
                    }
            }
       
        }
        return ans; 
    }
};