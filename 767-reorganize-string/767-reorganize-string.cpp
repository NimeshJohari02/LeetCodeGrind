class Solution {
public:
    string reorganizeString(string str) {
        // for any to to not be the same the freq of any char should be less than n /2 
        unordered_map<char , int> mp;
        for(auto &it : str) mp[it]++;
        priority_queue<pair<int , char>> pq;
        for(auto &it : mp){
            pq.push({it.second , it.first});            
        }
	    if(2 * pq.top().first - 1 > str.size()) return "";
        string s ="";
        while(pq.size() >=2){
            auto mostFreq = pq.top();
            pq.pop();
            s+=mostFreq.second;
            auto secondFreq = pq.top();
            pq.pop();
            s+=secondFreq.second;
            if(mostFreq.first-1 > 0)
                pq.push({mostFreq.first-1 , mostFreq.second});
            if(secondFreq.first-1 >0)
            pq.push({secondFreq.first-1 , secondFreq.second});
        }
        if(pq.size() !=0){
            s+=pq.top().second;
            pq.pop();
        }
        return s;
    }
};