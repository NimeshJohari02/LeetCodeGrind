class Solution {
public:
    double getDistanceFromx2y2(int x1 , int y1 , int x2 , int y2 ){
       return sqrt(pow((y2-y1),2) + pow((x2-x1),2)) ;
    }
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int>ans;
        int miniCount =0;
        for(auto it : queries){
            miniCount=0;
            for(auto pt : points){
                if(ceil(getDistanceFromx2y2(pt[0],pt[1],it[0],it[1]))<=it[2]){
                    miniCount++;
                }
            }
            ans.push_back(miniCount);
            miniCount =0;
        }
        return ans;
    }
};