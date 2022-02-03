class Solution {
 public:
  // we need to figure out a merge interval so as to combine the balloons into
  // distince intervals and return the points.size() as ans
  static bool cmp(vector<int>& p1, vector<int>& p2) { return p1[1] < p2[1]; }

  int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), cmp);
    int ans = 0;
    int i = 0;
    int current_interval_max = 0;
    while (i < points.size()) {
      current_interval_max = points[i][1];
      while (i < points.size() - 1 &&
             current_interval_max >= points[i + 1][0]) {
        i++;
      }
      ans++;
      i++;
    }
    return ans;
  }
};