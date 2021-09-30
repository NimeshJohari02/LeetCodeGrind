class Solution {
public:
    int firstOccurance(vector<int>& v, int target, int i)
    {
        int l=0, h=i;
        if(l==h)
        {
            return l;
        }
        int start=-1, m;
        while(l<=h)
        {
            m=(l)+(h-l)/2;
            if(target==v[m] && l<=h)
            {
                start=m;
                h=m-1;
            }
            else if(target>v[m])
            {
                l=m+1;
            }
        }
        return start;
    }
    int lastOccurance(vector<int>& v, int target, int i)
    {
        int l=i, h=v.size()-1;
        if(l==h)
        {
            return h;
        }
        int end=-1, m;
        while(l<=h)
        {
            m=(l)+(h-l)/2;
            if(v[m]==target && l<=h)
            {
                end=m;
                l=m+1;
            }
            else if(target<v[m])
            {
                h=m-1;
            }
        }
        return end;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> ans {-1,-1};
        int l=0, h=n-1;
        int i=-1;
        if(nums.empty())
        {
            return ans;
        }
        while(l<=h)
        {
            int mid=(l)+(h-l)/2;
            if(target==nums[mid])
            {
                i=mid;
                break;
            }
            else if(target>nums[mid])
            {
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        int first=-1, last=-1;
        if(i==-1)
        {
            return ans;
        }
        else
        {
            first=firstOccurance(nums,target,i);
            last=lastOccurance(nums,target,i);
            ans[0]=first;
            ans[1]=last;
        }
        return ans;
    }
};