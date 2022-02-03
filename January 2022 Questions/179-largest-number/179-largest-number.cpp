class Solution {
public:
    static bool cmp(string x , string y){
        string xy = x.append(y);
        string yx = y.append(x);
        return xy>=yx;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>ans;
        for(auto &it : nums)
            ans.push_back(to_string(it));
        sort(ans.begin() , ans.end() , cmp);
        string arr="";
        for(auto &it : ans)
            arr+=it;
        int i = 0; 
        while(i<arr.length() and arr[i]=='0') i++;
        if(i==arr.length()) return "0";
        return arr;
    }
};