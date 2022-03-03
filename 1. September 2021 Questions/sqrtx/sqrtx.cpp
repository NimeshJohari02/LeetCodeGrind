class Solution {
public:
    int mySqrt(int x) {
    long int mid,start,end;
        start=1;
        end=x;
        while(start<=end)
        {
            mid=(start+end)/2;
            if(mid*mid==x)
            {
                return mid;
            }
            else if(mid*mid<x)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }     
        }
        return end;
    }
};