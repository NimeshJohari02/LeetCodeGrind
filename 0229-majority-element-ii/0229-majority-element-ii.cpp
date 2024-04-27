class Solution {
public:
    
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans ;
        int counter1 = 0 , counter2 =0 , element1 = INT_MIN , element2 = INT_MIN , n = nums.size();
        for(int i=0 ; i < nums.size() ; i++){
            if(counter1==0 && nums[i]!=element2){
                counter1=1;
                element1 = nums[i];
            }
            else if(counter2==0 && nums[i]!= element1){
                counter2=1 ;
                element2 = nums[i];
            }
            else if(nums[i]==element1)counter1++;
            else if(nums[i]==element2)counter2++;
            else {
                counter1--;
                counter2--;
            }
        }
        counter1=0 , counter2=0;
        for(auto &it : nums){
            if(it==element1)counter1++;
            else if(it==element2)counter2++;
        }
        if(counter1>=int(n/3)+1){
            ans.push_back(element1);
        }
        
        if(counter2>=int(n/3)+1){
            ans.push_back(element2);
        }
    return ans;
    }
    
};