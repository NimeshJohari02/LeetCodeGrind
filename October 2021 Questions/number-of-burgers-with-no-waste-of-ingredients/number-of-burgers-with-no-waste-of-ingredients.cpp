class Solution {
public:
    vector<int> numOfBurgers(int ts, int cs) {
        double x = (ts-2*cs)/2.0;
        if(floor(x)!=ceil(x) or ts<0 or cs<0 or ts-2*cs<0){
            return {};
        }
        int x1= (int) x;
        if(cs-x1<0){
            return {};
        }
        return {x1,cs-x1};
    }
};