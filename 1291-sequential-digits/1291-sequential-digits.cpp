class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int cntLow = 0; 
        int tmp = low; 
        while(tmp){
            cntLow++; 
            tmp /= 10; 
        }
        tmp = high; 
        int cntHigh = 0; 
        while(tmp) {
            cntHigh++;
            tmp /= 10; 
        }
        vector<int> res; 
        while(cntLow<=cntHigh) {
            for(int i = 1; i <= 10-cntLow; i++) {
                int pw = pow(10, cntLow-1);
                int num = 0; 
                for(int j = i; j < i+cntLow; j++) {
                    num += pw*j; 
                    pw /= 10; 
                }

                if(num>=low and num <= high) res.push_back(num);
                if(num>high) break;
            }
            cntLow++;
        }

        return res;
    }
}; 


class Solution {
public:
    vector<int> sequentialDigits(int l, int h) {
        queue<int> q;
        for(int i = 1; i <= 9; i++) {
            q.push(i);
        }
        vector<int> ret;
        while(!q.empty()) {
            int f = q.front();
            q.pop();
            if(f <= h && f >= l) {
                ret.push_back(f);
            }
            if(f > h)
                break;
            int num = f % 10;
            if(num < 9) {
                q.push(f * 10 + (num + 1));
            }
        }
        return ret;
    }
};

