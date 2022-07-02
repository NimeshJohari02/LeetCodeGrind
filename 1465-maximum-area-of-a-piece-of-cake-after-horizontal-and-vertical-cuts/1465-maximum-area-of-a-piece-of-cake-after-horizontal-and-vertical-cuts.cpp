class Solution {
public:
    int MOD=1e9+7;
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin() , hc.end());
        sort(vc.begin() , vc.end());
        int lhc = 0 , lvc = 0 , nh= hc.size() , nc = vc.size();
        lhc = max(hc[0] , h-hc[nh-1]);
        lvc = max(vc[0] , w-vc[nc-1]);
        for(int i=1 ; i < nh ; i++)
                lhc = max(lhc , hc[i]-hc[i-1]);
        for(int i=1 ; i < nc ; i++)    
            lvc = max(lvc , vc[i]-vc[i-1]);
        long long ans = (long long)lhc*lvc % (long long)MOD;
        return ans;
    }
};