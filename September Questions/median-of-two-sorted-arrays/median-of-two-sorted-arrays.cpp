class Solution {
public:
   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    while (!nums1.empty() and !nums2.empty())
    {
        int k = nums1.back();
        int j = nums2.back();
        if(k>j){
            ans.push_back(k);
            nums1.pop_back();
        }
        if(j>k){
            ans.push_back(j);
            nums2.pop_back();
        }
        if(j==k){
            ans.push_back(j);
            ans.push_back(k);
            nums2.pop_back();
            nums1.pop_back();
        }
    }
    while(!nums1.empty()){
        ans.push_back(nums1.back());
        nums1.pop_back();
    }
    while(!nums2.empty()){
        ans.push_back(nums2.back());
        nums2.pop_back();
    }
    int k = ans.size();
     cout<<k<<endl;
     cout<<ceil((double)(k-1)/2)<<endl;
     cout<<floor((double)(k-1)/2)<<endl;
     
    double d = ans[ceil((k-1) / 2.0)] + ans[floor((k-1) / 2.0)];
    return d / 2.00;
}
};