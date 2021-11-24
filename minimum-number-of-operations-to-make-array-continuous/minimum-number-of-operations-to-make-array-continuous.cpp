class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        //set for finding unique element 
        set<int>s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        vector<int>unique;
        for(int item:s){
            unique.push_back(item);
        }
        
        //sort the array(let unique.size= m  m*log(m))
        
        int ans = INT_MAX;
        for(int i=0;i<unique.size();i++)
        {
            int start = unique[i];
            int last = start+n-1;
            
            //search for element just grater than last
            vector<int>::iterator upper=upper_bound(unique.begin(),unique.end(),last);
            int len = upper- unique.begin();
            ans = min(ans,n-(len-i));
            
        }
       return ans;
    }
};



class Solution {
public:
int minOperations(vector<int>& arr) {
    int n = arr.size();
    if(n == 1) return 0;  //1 item is always continuous.
    sort(arr.begin(), arr.end());
	
	vector<int> a;   //Array to store unique elements
    for(int i = 0; i < n-1; i++) {
        while(arr[i] == arr[i+1]) i++;
        a.push_back(arr[i]);
    }
    if(arr.back() != a.back()) a.push_back(arr.back());
    
    int mx = 0;
    for(int i = 0, j = 0; i < a.size(); i++) {
        while(j <= i && (a[i]-a[j]+1) > n) j++;   //While our slide is invalid, keep reducing
        mx = max(mx, i-j+1);                          //Compare with the previous highest
    }
    return n - mx;
}
};

