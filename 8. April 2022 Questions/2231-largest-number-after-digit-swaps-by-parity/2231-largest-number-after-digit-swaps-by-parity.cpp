class Solution {
public:
    int largestInteger(int num) {
        vector<int>even , odd;
        int temp = num;
        while(temp){
            int curr= temp %10;
            temp /=10;
            if(curr %2 ==0) even.push_back(curr);
            else odd.push_back(curr);
        }
        sort(even.begin() , even.end() , greater<>() );
        sort(odd.begin() , odd.end() , greater<int>());
        string str = to_string(num);
        int n = str.size();
        string ans(n , '0');
        for(int i=n-1 ; i >=0  ; i--){
            int digit = str[i] - '0';
            if(digit %2 ==0) {
                ans[i] = even.back() + '0';
                even.pop_back();
            }
            else{
                ans[i] = odd.back()+'0';
                odd.pop_back();
            }
        }
        return stoi(ans);
    }
};