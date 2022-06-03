class Solution {
public:
    char findKthBit(int n, int k) {
        int flip = 0, len = (1 << n) - 1;
        while (k > 1) {
            if (k == len / 2 + 1)
                return '0' + (flip ^ 1);
            if (k > len / 2) {
                k = len + 1 - k;
                flip  = flip ^ 1; 
            }
            len /= 2;
        }
        return '0' + flip;
    }
};