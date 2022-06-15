class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z =0 , o =0 , t =0 ;
        for(int j =0 ; j < nums.size() ; j++){
            if(nums[j]==1)o++;
            else if(nums[j]==0)z++;
            else t++;
        }
        int i=0 ;
        while(i < nums.size())
        {
            while(z--){
                nums[i++]=0;
            }
            
            while(o--){
                nums[i++]=1;
            }
            
            while(t--){
                nums[i++]=2;
            }
        }
        return ;
    }
};