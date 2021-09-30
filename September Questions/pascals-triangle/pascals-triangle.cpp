class Solution {
public:
     // long long int NCR[31][31];
    // void getFactorial(){
    //     for(int i=0;i<=31;i++){
    //         for(int )
    //     }
    //     return ;
    // }
    vector<vector<int>> generate(int numRows) {
       // int coefficientMatrix[numRows][numRows];
        // getFactorial();
        vector<vector<int>>ans;
        ans.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int>Smallans;
            Smallans.push_back(1);
            for(int j=1;j<i;j++){
                int val=ans[i-1][j-1]+ans[i-1][j];
                // Smallans.push_back(val);
                Smallans.push_back(val);
            }
            Smallans.push_back(1); 
            ans.push_back(Smallans);
        }
        return ans;
    }
};