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

// Sample 108 ms Solution
/*KClosest1 -> is using the nth_element STL function 
std::nth_element() is an STL algorithm which rearranges the list in such a way such that the element at the nth position is the one which should be at that position if we sort the list.
It does not sort the list, just that all the elements, which precede the nth element are not greater than it, and all the elements which succeed it are not less than it.
Using that we pass the custom comparator using to calculate the distance from both the points using inline calculations to minimize stack and memory overhead.
*/
class Solution {
public:
    vector<vector<int>> kClosest1(vector<vector<int>>& points, int K) {
        auto comp = [] (vector<int>& p, vector<int>& q) {
        return p[0]*p[0] + p[1]*p[1] < (q[0]*q[0] + q[1]*q[1]);};
        
        nth_element(points.begin(), points.begin()+K, points.end(), comp);
        return {points.begin(), points.begin()+K};
    }  
    
    int compare(vector<int>& p, vector<int>& q) {
        return p[0]*p[0] + p[1]*p[1] - (q[0]*q[0] + q[1]*q[1]);
    }
    // The second Solution is to use 
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int lo = 0, hi = points.size()-1;
        
        while (lo < hi) {
            /*
            int j = partitionLomuto(points, lo, hi);
            if (j < K) {
                lo = j+1;
            } else if (j > K) {
                hi = j-1;
            } else break;
            */
            
            int j = partitionHoare(points, lo, hi);
            if (j < K) {
                lo = j+1;
            } else {
                hi = j;
            }
        }
        
        vector<vector<int>> res(points.begin(), points.begin()+K);
        return res; 
    }
    
    // Pivot should be 'hi'; otherwise, the inner loop may
    // replace the pivot, cause the last swap at the end to
    // corrupt the array. If you want to select a random pivot,
    // swap with the last index, at the very beginning.
    int partitionLomuto(vector<vector<int>>& points, int lo, int hi) {
        int pivot = hi; 
        
        int i=lo-1, pivotDis = distance(points[pivot]);
        for (int j = lo; j < hi; j++) {
            if (distance(points[j]) < pivotDis) {
                swap(points[++i], points[j]);
            }
        }
        
        swap(points[i+1], points[pivot]); 
        return i+1;
    }
    
    // For Hoare, the 'lo' should be the pivot to prevent infinite
    // recursion/loop (at the caller side).
    // Random pivot: swap the random pivot with position 'lo'.
    int partitionHoare(vector<vector<int>>& points, int lo, int hi) {
        int i = lo-1, j = hi+1;
        int pivot = lo, pivotDis = distance(points[pivot]);
        
        while (i < j) {
            do {i++; } while (i < hi && distance(points[i]) < pivotDis);
            do {j--; } while (j > lo && distance(points[j]) >= pivotDis);
            
            if (i < j) {
                swap(points[i], points[j]);
            }
        }
        
        return j;
    }
    
    int distance(vector<int>& p) {
        return p[0]*p[0] + p[1]*p[1];
    }
};

