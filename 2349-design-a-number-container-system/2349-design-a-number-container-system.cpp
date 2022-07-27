class NumberContainers {
public:
    // provide lookup and rever
    // number , pq<idx>
//      priority_queue<int , vector<int>, greater<int>>
    NumberContainers() {
        
    }
    
    unordered_map<int, int> inum;
    unordered_map<int, set<int>> numi;
    void change(int index, int number) {
        auto it = inum.find(index);
        if (it != inum.end())
            numi[it->second].erase(index);
        inum[index] = number;
        numi[number].insert(index);
    }
    int find(int number) {
        auto it = numi.find(number);
        return it == numi.end() || it->second.empty() ? -1 : *begin(it->second);
    }

};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */