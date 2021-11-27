class Solution {
public:
  
    int maxConsecutiveAnswers(string A, int k) {

        
        int start = 0, mx = INT_MIN,zeroCounter=0;
        for(int end=0 ; end<A.size() ; end++){
            if(A[end]=='F'){
                zeroCounter++;
            }
            while(zeroCounter>k){
                if(A[start]=='F'){
                    zeroCounter--;
                }
                start++;
            }

            mx = max(mx,end-start+1);
        }

        int mx1=INT_MIN;
        start = 0, zeroCounter=0;
        for(int end=0 ; end<A.size() ; end++){
            if(A[end]=='T'){
                zeroCounter++;
            }
            while(zeroCounter>k){
                if(A[start]=='T'){
                    zeroCounter--;
                }
                start++;
            }

            mx1 = max(mx1,end-start+1);
        }

        return max(mx1,mx);  
    }
};