class Solution {
public:    
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    vector<int>pre(arr.size());
    vector<int>ans;  
    for(int i=0 ; i< arr.size();i++){
        pre[i]=((i==0)?arr[0]:(arr[i]^pre[i-1]));
        cout<<pre[i]<<"   ";
    }
        cout<<"\n";
        for(auto q : queries ){
            int x = q[0];
            int y = q[1];
            if((x-1)<0){
                ans.push_back(pre[y]);
            }
            else{
            cout<<(pre[y]^pre[x-1])<<endl;
            ans.push_back(pre[y]^pre[x-1]);
            }
        }
        return ans;
    }
};