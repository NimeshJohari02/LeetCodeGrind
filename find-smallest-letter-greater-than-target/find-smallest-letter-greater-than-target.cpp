class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start =0;
        int end = letters.size()-1;
        while(end>=start){
            int mid = (start+end)/2;
            char mc = letters[mid];
            if(mc>target){
                end=mid-1;
            }
            else{
                start = mid+1;
            }
        }
       return letters[start%letters.size()];
    }
};