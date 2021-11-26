class Solution {
public:
//     static bool cmp(vector<int>&v1 , vector<int>&v2){
//         return v1[0]<v2[0];
//     }
//     int maxEnvelopes(vector<vector<int>>& envelopes) {
//        sort(envelopes.begin() , envelopes.end(), cmp) ;
//         for(auto it : envelopes)
//             cout<<it[0]<<"    "<<it[1]<<endl;
        
//         int overallMax =1;
//         const int N = envelopes.size();
//         vector<int>LIS(N, 1);
//         for(int i=0 ; i<N ; i++){
//             int currMax =0;
//             for(int j =i-1 ; j>=0 ; j--){
//                 if(envelopes[i][1]>envelopes[j][1] && envelopes[i][0]>envelopes[j][0]){
//                     currMax = max (currMax , LIS[j]);
//                 }
//             }
//             LIS[i]=1+currMax;
//             overallMax = max(overallMax , LIS[i]);
//         }
//         for(auto it : LIS){
//             cout<<it<<"    ";
//         }
//         return overallMax;
//     }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) 
{
	int size = envelopes.size();
	sort(envelopes.begin(), envelopes.end(), [](vector <int>& a, vector<int>&b){
		return a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]);
	});
	vector<int> collector;
	for(auto& pair: envelopes)
	{
		auto iter = lower_bound(collector.begin(), collector.end(), pair[1]);
		if(iter == collector.end()) collector.push_back(pair[1]);
		else if(*iter > pair[1]) *iter = pair[1];
	}
	return collector.size();
}
};