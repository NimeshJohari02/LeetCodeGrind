class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";
        set<string> mp;
        string startString="";
        for(int i=0 ; i < 2 ; i++)
            for(int j =0 ; j < 3 ; j++)
                startString+= to_string(board[i][j]);
        vector<vector<int>> index = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{4,2}};
        queue<string> q;
        mp.insert(startString);
        q.push(startString);
        int level =0 ;
        while(!q.empty()){
            int k = q.size();
            for(int j =0 ; j < k ; j++){
                string curr = q.front();
                cout<<curr<<"\n";
                q.pop();
                if(curr == target )return level;
                int zeroIdx = -1;
                for(int i=0 ; i < curr.size() ;i++)
                    if(curr[i]=='0') {
                        zeroIdx = i;
                        break;    
                    }
                vector<int> swapable = index[zeroIdx];
                for(int i=0 ; i < swapable.size() ;i++ ){
                    string newString = swaper(curr , zeroIdx , swapable[i]);
                    if(mp.find(newString) == mp.end())
                    {
                        mp.insert(newString);
                        q.push(newString);
                    }
                }
            }
           level++;
        }
        return -1 ;
    }
    
    string swaper(string curr , int idx1 , int  idx2){
        swap(curr[idx1] , curr[idx2]);
        return curr;
    }
};


