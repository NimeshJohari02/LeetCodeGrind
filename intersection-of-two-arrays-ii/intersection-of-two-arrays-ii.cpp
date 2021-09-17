class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       map<int,int>m1;
       map<int,int>m2;
      vector<int>ans;
      for(auto it : nums1){
        m1[it]++;
      }
      for(auto it : nums2){
        m2[it]++;
      }
    for(auto it : m1 ){
      if(m2[it.first]!=0){
        int k = min(m2[it.first],it.second);
        cout<<k<<endl;
        cout<<"it"<<it.first<<"    ->   "<<it.second<<endl;
        while(k--){
          ans.push_back(it.first);
        }
        } 
      }   
      return ans;
    }
};