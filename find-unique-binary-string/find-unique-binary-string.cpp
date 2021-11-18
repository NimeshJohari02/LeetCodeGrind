class Solution {
public:
    int stringToInt(string s){
        int ans =0;
        int count =0;
        while(!s.empty()){
            ans = ans+(s.back()-'0')*(1<<count);
            count++;
            s.pop_back();
        }
        return ans;
    }
    string getBinaryFromInt(int fixedSize , int num){
        string s ="";
        while(num){
            s+=(num%2)+'0';
            num/=2;
        }
        string zeros(fixedSize-s.size(),'0');
        cout<<zeros<<endl;
        s+=zeros;
        reverse(s.begin(),s.end());
        return s;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int sizeOfBStirng = nums[0].size();
        map<int,int>mp;
        for(auto it : nums){
            int in = stringToInt(it);
            cout<<in<<"    ";
            mp[in]++;
        }
        int ansInt =0;
        for(int i=0 ; i<(1<<sizeOfBStirng);i++){
            if(mp[i]==0){
                ansInt = i;
                break;
            }
        }
        cout<<"Ans INT"<<ansInt<<endl;
       return  getBinaryFromInt(sizeOfBStirng, ansInt);
    }
};