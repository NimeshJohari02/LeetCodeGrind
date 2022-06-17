class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& bc) {
        unordered_map<int ,int > mp;
        priority_queue<pair<int , int> > pq;
        // freq , num
        for(auto &it : bc)
            mp[it]++;
        for(auto &it : mp)
        {
            pq.push({it.second , it.first});
        }
        vector<int>ans;
        while(pq.size() >=2){
            auto mostFreq = pq.top();
            pq.pop();
            auto secondMostFreq = pq.top();
            pq.pop();
            ans.push_back(mostFreq.second);
            ans.push_back(secondMostFreq.second);   
        if(mostFreq.first-1 > 0)
                pq.push({mostFreq.first-1 , mostFreq.second});
            if(secondMostFreq.first-1 >0)
            pq.push({secondMostFreq.first-1 , secondMostFreq.second});
        }
        if(pq.size() !=0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
    return ans;
    }
};