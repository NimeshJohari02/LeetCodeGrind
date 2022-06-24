// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool cmp(const pair<int, int> &p1 , const pair<int, int>&p2){
        return p1.second  < p2.second;
    }
    int maxMeetings(int start[], int end[], int n)
    
    {
        vector<pair<int,int>> v;
        for(int i=0 ; i < n ; i++)
        v.push_back({start[i]  , end[i]});
        sort(v.begin() , v.end() , cmp);
        int ans = 1 ;
        int currEnd = v[0].second;
        for(int i=1 ; i < v.size() ;i++){
            if(currEnd < v[i].first) {
                ans++;
                currEnd = v[i].second;
            }
        }
    return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends