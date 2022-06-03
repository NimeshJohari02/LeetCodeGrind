class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        // divide and subtract
        int ans = 0;
        while(target && maxDoubles){
            if(target %2 ==0){
             target /=2;
                maxDoubles--;
            }
            else{
                target--;
            }
            ans++;
        }
        return ans + target -1 ;
    }
};

