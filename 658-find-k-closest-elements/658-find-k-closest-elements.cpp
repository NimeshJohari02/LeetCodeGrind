class Solution {
public:
    vector<int>SortingWay(vector<int>&arr , int k , int x){
          auto cmp =[x](const int &a , const int &b){
             return abs(a - x) < abs(b - x);
        };
        sort(arr.begin() , arr.end() , cmp);
        arr.resize(k);
        sort(arr.begin() , arr.end());
        return arr; 
    }
    // PQ NOT WORKING FOR SOME REASON ://///
    vector<int>pqWay(vector<int>&arr , int k , int x){
         auto cmp =[x](const int &a , const int &b){
             return abs(a - x) < abs(b - x) ? false : b>a ? false : true;
        };
       priority_queue<int , vector<int>  , decltype(cmp)> pq(cmp);
        for(auto &it : arr)
            pq.push(it);
        vector<int> ans;
        while(!pq.empty() ){
            ans.push_back(pq.top());
            pq.pop();
        }
        ans.resize(k);
        sort(ans.begin() ,ans.end());
        return ans;
    }
    
    vector<int>binarySearch(vector<int>&arr , int k , int x){
        int left = 0 , right = arr.size() - k;
        while(right > left){
            int mid = (left + right )>>1 ;
            if(x - arr[mid]  > arr[mid+k] - x)
                left = mid+1;
            else right = mid;
        }
        return vector<int>(arr.begin() + left , arr.begin() + left + k);
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // return pqWay(arr , k , x);
        return binarySearch(arr , k , x);
    }
};