class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n,int i=0) {
        int cnt =0;
        for(int i = 0; i <arr.size();i++){
            if(arr[i]==0){
                int prev = ( i== 0 || arr[i-1]==0) ?0:1;
                int right = (i==arr.size()-1 || arr[i+1]==0)?0:1;
                if(prev ==0 and right ==0){
                    cnt++;
                    arr[i]=1;
                }
            }
        }
        return cnt>=n?true:false;
    }
};
