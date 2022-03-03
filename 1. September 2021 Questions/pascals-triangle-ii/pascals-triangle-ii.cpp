class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>ans;
        ans.push_back({1});
        for(int i=1;i<=rowIndex;i++){
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
//         for(auto it : ans ){
// for(auto i :it){
//     cout<<i<<"    ";
// }       cout<<endl; 
//         }
    return ans.back();
    }
};


 