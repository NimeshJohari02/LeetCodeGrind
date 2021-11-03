class CustomStack {
 
    public:
     vector<int>arr;
    int back =-1;
    int capacity=0;
    CustomStack(int maxSize) {
        capacity=maxSize;
    }
    
    void push(int x) {
        if(back < capacity-1){
            arr.push_back(x);
            back++;
        }
        return;
    }
    int pop() {
        if(!arr.empty()){
            int x =  arr.back();
            arr.pop_back();
            back--;
            return x;
        }
            back =-1;
            return -1;
    }
    
    void increment(int k, int val) {
    int x=k;
        if(arr.size()<k)
            x=arr.size();
        for(int i=0;i<x;i++)
        {
            arr[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */