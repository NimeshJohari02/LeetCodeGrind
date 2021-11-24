class Solution {
public:
    // My Approach O(min(m ,n)
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i =0 ;
        int j =0;
        vector<vector<int>>ans;
        while(i < firstList.size() and j < secondList.size()){
            cout<<" Starting Of 1st "<<firstList[i][0]<<" Ending "<<firstList[i][1]<<endl;
            cout<<" Starting Of 2nd "<<secondList[j][0]<<" Ending "<<secondList[j][1]<<endl;
               if(   firstList[i][1] <= secondList[j][1]){
                    cout<<"Inside i condn"<<endl;
                   int leftInterval = max(firstList[i][0],secondList[j][0]) ;
                   int rightInterval =min(firstList[i][1],secondList[j][1]);
                    if(rightInterval >= leftInterval){
                    ans.push_back({leftInterval,rightInterval });                        
                    }
                    i++;
               }
               else if( firstList[i][1] >= secondList[j][1]){
                    cout<<"Inside j condn"<<endl;
                   
                   int leftInterval = max(firstList[i][0],secondList[j][0]);
                   int rightInterval =min(firstList[i][1],secondList[j][1]);
                    if(rightInterval >= leftInterval){
                    ans.push_back({leftInterval,rightInterval });                        
                    }
                   j++;
               }
        }
        return ans;
    }
};



// Another Appoarch Same Idea Cleaner Implimentation . 
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> v;
        int i=0,j=0;
        while(i<A.size() && j<B.size()){
            int l=max(A[i][0], B[j][0]);
            int u=min(A[i][1], B[j][1]);
            if(l<=u) v.push_back({l,u});
            if(A[i][1] < B[j][1])   i++;
            else j++;
        }
        return v;
    }
};

// Approach II .
  vector<vector<int>> res;
    for (auto i = 0, j = 0; i < A.size() && j < B.size(); A[i][1] < B[j][1] ? ++i : ++j) {
        auto start = max(A[i][0], B[j][0]);
        auto end = min(A[i][1], B[j][1]);
        if (start <= end) 
            res.push_back({start, end});
    }
    return res;    
}
