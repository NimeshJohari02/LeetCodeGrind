class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
	{
      int total =0 ;
        int currSum = INT_MAX;
        int start =0;
        for(int i =0 ; i < gas.size() ; i++){
            int currNeed = gas[i] - cost[i];
            cout<<currNeed<<"  ";
            total += currNeed;
            if(total < currSum){
                currSum = total ;
                start = i+1;
            }
        }
        return (total < 0) ?  -1 : (start % gas.size()); 
    }
};

/*
class Solution {
public:
    Solution() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int n = gas.size();
        int sum = 0, min_sum = std::numeric_limits<int>::max(), min_i = -1;
        for (int i = 0; i < n; ++i) {
            sum += gas[i] - cost[i];
            if (sum < min_sum) {
                min_sum = sum;
                min_i = i;
            }
        }
        return sum >= 0 ? ((min_i + 1) % n) : -1;
    }
};*/