#include <bits/stdc++.h>
using namespace std;
pair<int, int> repeatingNumber(vector<int> &arr)
{
    int n = arr.size(), repeating, missing;
    // Using ExtraSpace --> EZ use an array of size n
    // TC -- O(n) + Space --> O(n)
    vector<int> ansVector(n + 1, 0);
    for (int i = 0; i < arr.size(); i++)
        ansVector[arr[i] - 1]++;
    for (int i = 0; i < arr.size(); i++)
    {
        if (ansVector[i] > 1)
            repeating = i + 1;
        if (ansVector[i] == 0)
            missing = i + 1;
    }
    return {repeating, missing};
}
pair<int, int> optimizedSolution(vector<int> &arr)
{
    int n = arr.size();
    pair<int, int> ans;
    // X --> Missing Number , Y --> Duplicate Number
    // 1 2 2 4 . Here x = 3 and y = 2 ;
    // Hence X^Y = 1 2 2 4 ^(1 2 3 4)= 1 ^ 1 ^ 2 ^ 2 ^2 ^ 3 ^ 4 ^ 4
    // In our case X ^ Y = 3 ^ 2 - 11 ^ 10 --> 1 (Only one set BIT)
    // SubPart A Have setBit  --> 1
    // SubPart B Dont have set Bit --> 2 2 4
    int currentXor = 0;
    for (int i = 0; i < n; i++)
    {
        currentXor = currentXor ^ arr[i];
        currentXor = currentXor ^ (i + 1);
    }
    int lastSetBit = (currentXor & ~(currentXor - 1));
    int group1 = 0, group2 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if ((arr[i] & lastSetBit) != 0)
            group1 ^= arr[i];
        else
            group2 ^= arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if ((i & lastSetBit) != 0)
        {
            group1 = group1 ^ i;
        }
        // part of 2 group:
        else
        {
            group2 = group2 ^ i;
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == group1)
            count++;
    if (count == 2)
        return {group1, group2};
    else
        return {group2, group1};
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    auto ans = optimizedSolution(arr);
    cout << "Repeating Number " << ans.first << "  Missing Number = " << ans.second;
    return 0;
}