class Solution {
public:
    /* 
    1. For Union Find we generally maintain a DSU class . And the implentation consists of a few vectors . But in our case that DSU class will not work in order to facilitate the storing of negative numbers . 
    */
    int find(vector<int>& ds,int i){
        return ds[i]<0?i:ds[i]=find(ds,ds[i]);
    }
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int seq=0;
        vector<int> ds(nums.size(),-1);
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();++i){
            int n=nums[i];
            if(m.count(n))
                continue;
            m[n]=i;
            if(m.count(n-1)){
                //union
                int j=find(ds,m[n]);
                int k=find(ds,m[n-1]);
                ds[j]+=ds[k];
                ds[k]=j;
            }           
            if(m.count(n+1)){
                //union
                int j=find(ds,m[n]);
                int k=find(ds,m[n+1]);
                ds[j]+=ds[k];
                ds[k]=j;
            }
            seq=max(seq,abs(ds[find(ds,m[n])]));
        }
        return seq;
    }
};

/*

HashMap Approach 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
     unordered_map<int , int> mp;
        if(nums.size() ==0) return 0;
        for(auto &it : nums) mp[it]++;
        int ls = 1;
        for(int i=0 ; i < nums.size() ; i++){
         int curr = nums[i];
            if(mp[curr-1]==0){
                int modNum = curr;
                int cs = 1;
                while(mp[modNum+1] >0){
                    modNum+=1;
                    cs++;
                }
                ls = max (ls , cs);
            }
        }
        return ls;
    }
};


*/