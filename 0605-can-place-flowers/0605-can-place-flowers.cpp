class Solution {
public:
    bool isPossibleArrangement(vector<int>&arr , int currIdx){
        if(arr[currIdx]==1)return false ;
        // we can now assume that 3 size of bed is min 
        if (currIdx == 0) return  arr[currIdx+1] == 0 ;
        if (currIdx == arr.size()-1) return arr[currIdx-1] == 0 ;   
        return arr[currIdx-1] ==0 && arr[currIdx +1] == 0 ;
    }
    bool canPlaceFlowers(vector<int>& arr, int n) {
        int max =0 ;
        if(n==0)return true ;
        if(arr.size()==1) return arr[0] == 0 ;
        if(n > arr.size()) return false ;
         for(int i=0 ; i < arr.size() ; i++){
            if(isPossibleArrangement(arr , i)){
                max++ ;
                arr[i]=1 ;
            }
        }
    return max>=n;
    }
};