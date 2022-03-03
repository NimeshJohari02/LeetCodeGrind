class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0,bit=0;
    for(int i=0;i<32;i++)
    {
    bit=1<<i; 
    if(n&bit)
    ans|=(1<<(32-i-1));
    }
    return ans;
    }  
};