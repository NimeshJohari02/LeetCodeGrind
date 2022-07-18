class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26 , 0 );
        int maxFreq = 0 ;
        for(auto &it : tasks)
            freq[it-'A']++ , maxFreq = max(maxFreq , freq[it-'A']);
        int val =  0 ;
        for(auto &it : freq) 
            if(it == maxFreq) 
                val++;
        return max((int)tasks.size(), (maxFreq-1)*(n+1) + val);
    }
};