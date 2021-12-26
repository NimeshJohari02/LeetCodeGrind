class Coordinates{
        public :
        vector<int>crd;
        Coordinates(vector<int>&point){
            crd=point;
        }
    };
    double distance(Coordinates &p1){
        return sqrt(pow(p1.crd[0],2)+pow(p1.crd[1],2));
    }
    class CoordinatesCmp{
      public:
        bool operator()(Coordinates c1 ,Coordinates c2){
            return distance(c1) > distance(c2);
        }
    };

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Coordinates , vector<Coordinates> ,CoordinatesCmp> pq;
        for(auto & it:points){
            Coordinates c = Coordinates(it);
            pq.push(c);
        }
        vector<vector<int>>ans;
        // int del = points.size()-k ;
        // while(!pq.empty()){
        //     cout<<pq.top().crd[0]<<"   "<<pq.top().crd[1]<<"   \n";
        //     pq.pop();
        // }
        for(int i=0 ; i < k ; i++){
            ans.push_back(pq.top().crd);
            pq.pop();
        }
        return ans;
    }
};

