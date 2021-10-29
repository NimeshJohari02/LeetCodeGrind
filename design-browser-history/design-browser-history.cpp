class BrowserHistory {
public:
     vector<string> hist;
    int curr; 

    BrowserHistory(string homepage) {
        
        hist.push_back(homepage); 
        curr = 0; 
    }

    void visit(string url) {
        if(curr== hist.size()-1){
            hist.push_back(url); 
            curr+=1; 
        } else {
            int i = hist.size()-1; 
            while(i>curr){
                hist.pop_back(); 
                i--; 
            }
            hist.push_back(url);
            curr = hist.size()-1;
        }        
    }

    string back(int steps) {
        if(steps>=curr){
            steps = curr;
        }
        
        while(steps){
            curr--;
            steps--; 
        }
        return hist[curr];
    }

    string forward(int steps) {
        steps = steps>=(hist.size()-curr)?(hist.size()-1-curr):steps;
        while(steps){
            curr++;
            steps--; 
        }
        return hist[curr];
    }

};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */