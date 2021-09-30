class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      int i=0;
      int j =nums.size()-1;
      vector<int> ans;
      while(j>=i){ 
        cout<<"i ="<<i<<"j ="<<j<<endl;
        int n1 = abs(nums[i]);
        int n2 = abs(nums[j]);
        if(n1>n2){
          ans.push_back(n1);
          i++;
        }
      else if(n2>n1){
        ans.push_back(n2);
        j--;
      }
      else{
        if(i==j){
        ans.push_back(n1);
        break;
        }
        else{
        ans.push_back(n1);
        ans.push_back(n1);
        i++;
        j--;
        }
      }
      }
  for(int i=0;i<ans.size();i++){
    ans[i]=pow(ans[i],2);
  }
      reverse(ans.begin(),ans.end());
  return ans;
    }
};