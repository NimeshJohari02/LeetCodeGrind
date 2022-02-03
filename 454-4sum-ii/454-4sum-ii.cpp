class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // for(auto&a:nums1)
        //     for(auto&b:nums2)
        //         for(auto&c:nums3)
        //             for(auto&d:nums4)
        //                 if((a+b+c+d)==0)
        //                     ans++;
//         unordered_map<int,int> threeSum ;
//            for(auto&a:nums1)
//             for(auto&b:nums2)
//                 for(auto&c:nums3)
//                     threeSum[a+b+c]++;
//         for(auto&d:nums3)
//             if(threeSum.find(-d) != threeSum.end())
//                 ans+=threeSum[-d];
        
        unordered_map<int, int > m1;
        for(auto &i1 : nums1)
            for(auto &i2:nums2)
                m1[i1+i2]++;
        int ans =0;
        for(auto&i1:nums3){
            for(auto&i2 : nums4){
                int need = -(i1+i2);
                if(m1.find(need) != m1.end())
                    ans+=m1[need];
            }
        }
         return ans;
    }
};