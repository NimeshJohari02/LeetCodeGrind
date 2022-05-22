class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // Nearest smaller to right 
        // Since we have been given that the number is a permuation we can say that every  number will 
        // the correct position will be at i . 
        int currMax = INT_MIN , cluster =0;
        for(int i=0 ; i < arr.size() ; i++){
            currMax = max(currMax , arr[i]);
            if(i==currMax) cluster++;
        }
        return cluster;
    }
};