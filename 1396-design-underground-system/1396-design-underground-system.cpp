class UndergroundSystem {
public:
    // Passenger 
    unordered_map<int , pair<string , int >> p;
    // Start Stations 
    // start , end , time , number ;
    map<pair<string , string> , pair<double , int>> ansMap;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string sname, int t) {
     p[id]={sname, t};   
    }
    
    void checkOut(int id, string sname, int t) {
        auto prev = p[id];
        auto prevTimeStation = ansMap[{prev.first , sname}];
        ansMap[{prev.first ,sname }]  = { prevTimeStation.first + (t-prev.second) , prevTimeStation.second+1};
        
    }
    
    double getAverageTime(string s, string e) {
    
        auto it = ansMap[{s , e}];
        return double(it.first / it.second);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */