class Solution {
public:
    // determine the highest power of 2 you need to divide these number so as to bring them closer and then subtract 
    
    // decrement and double  
    int brokenCalc(int start, int target) {
        // if(start >= target) return start - target ;
        // if(start == 1) return floor (log2(target)) +  (target - pow(2 , floor(log2(target))));
        // return ceil(log(target) / log(start));
        int ans =0;
        if(start > target) return  start - target;
        while(target != start ) {
        if(start > target) return ans + start - target;
        if(target %2 ==0 ) target /=2 ;
        else target ++;    
        ans++;
    }
        return ans ;
    }
};