class Solution {
public:
  int getSetBits(int n){
    int ans =0;
    while(n){
      n=n&n-1;
      ans++;
    }
    return ans;
  }
    vector<int> countBits(int n) {
     vector<int>ans;
      for(int i=0;i<=n;i++){
        ans.push_back(getSetBits(i));
      }
      return ans;
    }
  
};