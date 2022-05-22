class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int , int > mp;
        for(auto &task : tasks)
            mp[task]++;
        int days =0 ;
        //Task List 
        /*
        ceil( n / 3)
        1 = -1 
        2 = 1
        3 = 1 
        4 =  (2 + 2) = 2days
        5 = (2+3) = 2 days
        6 = 3 + 3 = 2days
        7 = (3 + 2 + 2) = 3
        8 = (3 + 3 + 2)
        */
        for(auto &it : mp)
        {
            if(it.second ==1 ) return -1 ;
            days += ceil(it.second /(3.0) );
        }
        return days;
    }
};