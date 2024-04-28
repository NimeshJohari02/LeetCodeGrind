#include <vector>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    void getPermutation(vector<int> nums, int i = 0)
    {
        if (i == nums.size() - 1)
        {
            ans.push_back(nums);
        }
        for (int j = i; j < nums.size(); j++)
        {
            swap(nums[i], nums[j]);
            getPermutation(nums, i + 1);
            // Backtrack
            swap(nums[i], nums[j]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        getPermutation(nums, 0);
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Solution *s1 = new Solution();
    vector<vector<int>> ans = s1->permute(arr);
    for (auto &it : ans)
    {
        for (auto &iit : it)
            cout << iit << " ";
        cout << "\n";
    }
    return 0;
}
