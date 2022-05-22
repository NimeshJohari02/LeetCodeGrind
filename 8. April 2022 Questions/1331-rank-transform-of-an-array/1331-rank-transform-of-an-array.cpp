class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
    set<int> s(arr.begin(),arr.end());
	unordered_map<int,int> mp;
	int rank=1;
	for(auto &it: s)  mp[it]=rank++;
	for(auto &it: arr) it = mp[it];
	return arr;
    }
};