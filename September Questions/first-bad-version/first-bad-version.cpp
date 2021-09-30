// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
#define ll long long int
class Solution {
public:
    ll firstBadVersion(ll n) {
    ll s=1;
    ll e = n;
    while(e>=s){
      ll mid = (e+s)/2;
      if(isBadVersion(mid)){
        e=mid-1;
      }
      else{
        s=mid+1;
      }
    }  
      return s;
    }
};