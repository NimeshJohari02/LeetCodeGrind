class Solution {
public:
  static bool cmp(string &a,string &b)
    {
        if(a.size()==b.size())
        {
            return a<b;
        }
        return a.size()<b.size();
    }
    string kthLargestNumber(vector<string>& nums, int k) {
         sort(nums.begin(),nums.end(),cmp);
        return nums[nums.size()-k];
    }
};
// Another approach isto use Heap . But since the comparision logic is not a standard . We have to make a custom HeapCmp Class and in that class overload the operator ()
// InOrder to facilitate the ordering of elements in the fashion that we want .
class NumStrMinComparator {
public:
    bool operator() (string &b, string &a) { // Please note, I swap position of `a` and `b` here!
        if (a.size() != b.size()) return a.size() < b.size();
        return  a < b;
    }
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, NumStrMinComparator> minHeap;
        for (string& num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};
