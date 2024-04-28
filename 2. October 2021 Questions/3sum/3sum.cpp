#include <bits/stdc++.h>
using namespace std;
// class Solution
// {
// public:
//     vector<vector<int>> threeSum(vector<int> &nums)
//     {
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> ans;

//         for (int i = 0; i < nums.size(); i++)
//         {
//             int target = -nums[i];
//             int front = i + 1;
//             int back = nums.size() - 1;
//             while (back > front)
//             {
//                 int sum = (nums[front] + nums[back]);
//                 if (sum > target)
//                 {
//                     back--;
//                 }
//                 else if (sum < target)
//                 {
//                     front++;
//                 }
//                 else
//                 {
//                     vector<int> ansCandidate = {nums[i], nums[front], nums[back]};
//                     ans.push_back(ansCandidate);
//                     while (back > front and nums[front] == ansCandidate[1])
//                         front++;
//                     while (back > front and nums[back] == ansCandidate[2])
//                         back--;
//                 }
//             }
//             while (i + 1 < nums.size() and nums[i] == nums[i + 1])
//             {
//                 i++;
//             }
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &arr)
    {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++)
        {
            if (i != 0 && arr[i] == arr[i - 1])
                continue;
            int j = i + 1, k = arr.size() - 1;
            while (j < k)
            {
                int threeSum = arr[i] + arr[j] + arr[k];
                if (threeSum == 0)
                {
                    ans.push_back({arr[i], arr[j], arr[k]});
                    j++;
                    k--;
                    while (j < k && arr[j] == arr[j - 1])
                        j++;
                    while (j < k && arr[k] == arr[k + 1])
                        k--;
                }
                if (threeSum > 0)
                    k--;
                else if (threeSum < 0)
                    j++;
            }
        }
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
    auto ans = s1->threeSum(arr);
    for (auto &it : ans)
    {
        for (auto &iit : it)
        {
            cout << iit << " ";
        }
        cout << "\n";
    }
    return 0;
}