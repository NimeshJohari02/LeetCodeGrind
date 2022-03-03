class Solution {
public:
    bool isPerfectSquare(int num){
        double dd = (double) num;
        double sqrtNum = sqrt(dd);
        return floor(sqrtNum) == ceil(sqrtNum);
    }
    bool winnerSquareGame(int n) {
        vector<bool>winner(n+1 , false);
        winner[1]= true;
        for(int i=2 ; i <= n ; i++){
            if(isPerfectSquare(i)){
                winner[i] = true;
            }
        }
        for(int i=0 ; i<=n ; i++){
            for(int k=1 ; k*k<=i ; k++){
                if (winner[i - k * k] == false) {
                    winner[i] = true;
                    break;
                }
            }
        }
         return winner[n];
    }
};