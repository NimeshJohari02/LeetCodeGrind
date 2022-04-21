class MyHashSet {
public:
    vector<int>occ;
    MyHashSet() {
        occ.resize(1000001);
    }
    void add(int key) {
     occ[key]=1;
    }
    
    void remove(int key) {
        occ[key]=0;
    }
    
    bool contains(int key) {
        cout<<key<<"  "<<occ[key]<<"\n";
        return occ[key]>=1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */