class Solution {
public:
    string reorganizeString(string str) {
	    // // for any to to not be the same the freq of any char should be less than n /2 
	    // unordered_map<char , int> mp;
	    // for(auto &it : str) mp[it]++;
	    // priority_queue<pair<int , char>> pq;
	    // for(auto &it : mp){
	    // pq.push({it.second , it.first});            
	    // }
	    // if(2 * pq.top().first - 1 > str.size()) return "";
	    // string s ="";
	    // while(pq.size() >=2){
	    // auto mostFreq = pq.top();
	    // pq.pop();
	    // s+=mostFreq.second;
	    // auto secondFreq = pq.top();
	    // pq.pop();
	    // s+=secondFreq.second;
	    // if(mostFreq.first-1 > 0)
	    // pq.push({mostFreq.first-1 , mostFreq.second});
	    // if(secondFreq.first-1 >0)
	    // pq.push({secondFreq.first-1 , secondFreq.second});
	    // }
	    // if(pq.size() !=0){
	    // s+=pq.top().second;
	    // pq.pop();
	    // }
	    // return s;
        vector<int>mp(26 );
        int n = str.size() , mxCnt = INT_MIN;
        string ans(n , ' ');
        char mostFreq ;
        for(auto &it : str){
            mp[it-'a']++;
            if(mp[it-'a'] > mxCnt){
                mxCnt = mp[it-'a'];
                mostFreq =it;
            }
        }
        // cout<<"Most freq is "<< mostFreq<<"\n";
        if( 2* mp[mostFreq-'a']-1 > n) return ""; 
        int i=0;
        while(mp[mostFreq-'a']>0)
        {
            ans[i] = mostFreq ;
            mp[mostFreq-'a']--;
            i+=2;
         }
        
        for(int j=0 ; j< 26 ; j++){
            while(mp[j]){
            if(i >= str.size()) i = 1;
			ans[i] = ('a' + j);
            mp[j]--;
			i += 2;
            }
        }
        return ans;
    }
};