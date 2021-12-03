class Solution {
public:
    string longestPalindrome(string s) {
        // Single Char Always Pallindrome 
        if (s.size() < 2)
            return s;
        int len = s.size(), max_left = 0, max_len = 1, left, right;
        // Using left and right to denote the start and end of the window and finally updating 
        // thr maxLength to right - left +1 (Window Size) in our case will be length of the longest Pallindromic Substring
        
        
        for (int start = 0; start < len && len - start > max_len / 2;) {
            left = right = start;
            cout<<" Left "<<left <<" Right "<<right <<"  Start "<<start;
            // For every char left in init to start and we expand the window from there to find pallindrome and keep moving right
            //Same letter would always contribute to being a pallindrome in any substring. so find the largest length of consecutive characters with the below given loop While checking for the boundary condition .
            while (right < len - 1 && s[right + 1] == s[right]  ){
                right++;
            }
            
            start = right + 1;
            
            while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                right++;
                left--;
            }
            if (max_len < right - left + 1) {
                max_left = left;
                max_len = right - left + 1;
            }
        }
        return s.substr(max_left, max_len);
    }
};