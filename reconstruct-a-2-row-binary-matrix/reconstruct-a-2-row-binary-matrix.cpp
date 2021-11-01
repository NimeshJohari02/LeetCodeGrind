class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int cs =0;
        for(auto it : colsum){
            cs+=it;
        }
        if(cs!=(upper+lower)){
            return {};
        }
        vector<vector<int>> possilbleAns( 2 , vector<int> (colsum.size(), 0));
        int cus=0;
        int cds =0;
        // first fill 2 then allot one 
        for(int i =0 ; i< colsum.size();i++){
            if(colsum[i]==2){
                cus++;
                cds++;
                possilbleAns[0][i]=1;
                possilbleAns[1][i]=1;
            }
        }
    
        for(int i =0 ; i < colsum.size();i++){
            if(colsum[i]==1){
                if(cus<upper){
                    possilbleAns[0][i]=1;
                    cus++;
                    continue;
                }
                  if(cds<lower){
                    possilbleAns[1][i]=1;
                    cds++;
                    continue;
                }
            }
            
        }
        if(cds!= lower || cus != upper ){
            return {};
        }
        return possilbleAns;
    }
};