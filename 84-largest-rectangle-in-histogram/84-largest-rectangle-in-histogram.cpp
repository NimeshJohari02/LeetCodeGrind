class Solution {
public:
    int area(vector<int> &arr) {
  int n = arr.size();
  vector<int> nsl(n, 0), nsr(n, 0);
  stack<int> stk;
  // nsl
  for (int i = 0; i < n; i++) {
    while (!stk.empty() && arr[i] <= arr[stk.top()])
      stk.pop();
    if (stk.empty())
      nsl[i] = 0;
    else
      nsl[i] = stk.top() + 1;
    stk.push(i);
  }
  stk = stack<int>();
  for (int i = n - 1; i >= 0; i--) {
    while (!stk.empty() && arr[i] <= arr[stk.top()])
      stk.pop();
    if (stk.empty())
      nsr[i] = n - 1;
    else
      nsr[i] = stk.top() - 1;
    stk.push(i);
  }
  int ans = INT_MIN;
  for (int i = 0; i < n; i++)
    ans = max(ans, (nsr[i] - nsl[i] + 1) * arr[i]);
  return ans;
}
    int largestRectangleArea(vector<int>& heights) {
        return area(heights);
    }
};