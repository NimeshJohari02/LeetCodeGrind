class Solution {
public:
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
