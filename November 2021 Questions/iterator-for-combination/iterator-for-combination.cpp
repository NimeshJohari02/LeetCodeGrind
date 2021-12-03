class CombinationIterator {
public:
    int len=0;
    vector<string>ans;
    void helper(string ip , string op){
        if(ip.empty()){
            if(op.size()==len){
                ans.push_back(op);
            }
            return;
        }
        string s1(op);
        string s2(op);
        s2.push_back(ip.back());
        ip.pop_back();
        helper(ip,s1);
        helper(ip,s2);
        return;
    }
    CombinationIterator(string characters, int combinationLength) {
        string op="";
        len=combinationLength;
        reverse(characters.begin(),characters.end());
        helper( characters ,  op);
         // sort(ans.begin(),ans.end());
        
    }
    string next() {
        string temp = ans.back();
        ans.pop_back();
        return temp;
    }
    
    bool hasNext() {
        return !ans.empty();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */