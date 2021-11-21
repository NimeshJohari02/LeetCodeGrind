class RangeFreqQuery {
    private:
    map<int,vector<int>>mp;
public:
    RangeFreqQuery(vector<int>& arr) {
        cout<<"hello"<<endl;
        for(int i=0 ; i<arr.size(); i++){
            mp[arr[i]].push_back(i);
        }
    }
    int lowerBound(vector<int>&arr , int val){
        int lo = 0;
        int mid;
        cout<<"hello lb"<<endl;
        int n = arr.size();
        int high=n-1;
        while(high>=lo){
             mid = lo + (high-lo)/2;
            
            if(arr[mid]>=val){
                high=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        if(lo < n && arr[lo] < val) {
       lo++;
    }
        cout<<lo;
        return arr[lo];
    }
    
    int UpperBound(vector<int>&arr , int val){
        int lo = 0;
        int n = arr.size();
        int high=n-1;
        cout<<"hello ub"<<endl;
        
        while(high>=lo){
            int mid = lo + (high-lo)/2;
            int currentVal = arr[mid];
            if(currentVal>=val){
                lo=mid+1;
                         }
            else{
                high=mid-1;
            }
        }
        if(lo < n && arr[lo] <= val) {
       lo++;
        }
        cout<<lo;
        return arr[lo];
    }
    int query(int left, int right, int value) {
        vector<int>&vc = mp[value];
        int lb = lower_bound(vc.begin(),vc.end(),left)-vc.begin();
        int ub = upper_bound(vc.begin(),vc.end(),right)-vc.begin();
        return ub-lb;
        
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */