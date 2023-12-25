class Solution {
public:
    // piles.length <= h <= 109
    bool canConsumeInHours(vector<int>&arr , int speed , long long int h){
        int hrs = 0 ;
        for(auto it : arr){
        hrs += it/speed + (it%speed != 0);
        }
        return hrs <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int minSpeed = 1 ; 
        int maxSpeed = *max_element(piles.begin() , piles.end());
        while(maxSpeed > minSpeed){
            long long int currSpeed = minSpeed + (maxSpeed - minSpeed)/2;
            if(canConsumeInHours(piles , currSpeed , h)){
                maxSpeed = currSpeed;
            }
            else 
                minSpeed = currSpeed+1;
        }
    return maxSpeed;
    }
};