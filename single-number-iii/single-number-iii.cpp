class Solution {
public:
    int highestSetBit(int n ){
    int msb = 0;
    while((n&1)==0){
        msb++;
        n = n >> 1;
    }
    return msb;
}
    bool isSelectBitSet(int n , int i ){
    int ans = n & (1 << i);
    return (ans > 0 ? true : false);
}
    
    vector<int> singleNumber(vector<int>& nums) {
     int xorArray = 0 ;
        for(auto it : nums){
            xorArray = xorArray ^ it;
        }
        cout<<xorArray<<endl;
           vector<int>ans;
           int temp = xorArray;
         int pos =highestSetBit(temp);
         for(auto i : nums){
        if(isSelectBitSet(i,pos)){
            temp = temp ^ i;
       }
    }
       ans.push_back( temp);
       ans.push_back(temp ^ xorArray);
        return ans;
    }
};