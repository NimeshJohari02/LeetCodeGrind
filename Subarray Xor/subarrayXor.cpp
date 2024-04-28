#include <bits/stdc++.h>
using namespace std;
int subarrayXorK(vector<int> &arr, int k)
{
    int n = arr.size(), prefixXor = 0, ans = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        prefixXor = prefixXor ^ arr[i];
        ans += mp[prefixXor ^ k];
        mp[prefixXor]++;
    }
    return ans;
}
int main()
{
    int n, k;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    cout << subarrayXorK(arr, k);
    return 0;
}