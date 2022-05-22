class ATM {
public:
    // USE ll otherwise it will result in runtime in certain cases.
    vector<long long int >notes = {20, 50 , 100 , 200 , 500};
    vector<long long int >available={0 , 0 , 0 , 0 , 0};
    ATM() {
    }
    
    void deposit(vector<int> arr) {
        for(int i=0 ; i < arr.size() ; i++)
            available[i] += arr[i];
    }
    
    vector<int> withdraw(int amount) { 
        vector<int>ans(5 , 0);
        // Go for the highest note denomination first . 
        /*
        The number of notes you can choose will be the minimum of the available and the needed notes . Once assign the notes 
        Once they are assigned check whether you were able to fullfil the transaction ie amount should be 0 . If yes then confirm the transaction by removing the number of notes from the array . 
        else return {-1};
        */
        for(int i=4 ; i >=0 ; i--){
            ans[i] = min(available[i] , amount / notes[i]);
            amount -= ans[i] * notes[i];
        }
        if(amount != 0) return {-1};
        for(int i=0 ; i < 5 ; i++)
        {
            available[i] -= ans[i];
        }
        return ans;
    }
};
/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */