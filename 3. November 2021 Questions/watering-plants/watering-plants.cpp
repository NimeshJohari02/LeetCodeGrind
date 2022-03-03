class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans =0;
        int currentcpt = capacity;
        for(int i =0 ; i< plants.size(); i++){
            if(plants[i]<=currentcpt){
                ans++;
                currentcpt-=plants[i];
            }
            else{
                ans+=2*(i)+1;
                currentcpt=capacity-plants[i];
            }
        }
        return ans;
    }
};