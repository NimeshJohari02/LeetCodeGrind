class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        // For each commodity of cost1 add as much of cost2 you can buy then loop over cost1 capacity;
        long long qty1 = total / cost1;
        long long ans =0;
        // From 0 to qty as 0 would also be a distinct case 
        for(int i=0 ; i <= qty1 ; i++){
            ans += (total - i* cost1) / cost2 + 1; // 1 for this current way
        }
        return ans;
    }
};


