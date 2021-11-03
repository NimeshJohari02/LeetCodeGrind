```class MyCalendar {
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        for (auto [s, e] : calendar)
            if (max(s, start) < min(e, end)) return false;
        
        calendar.push_back({start, end});
        return true;
    }
    
private:
    vector<pair<int, int>> calendar;
};
```
## This is a NLogN Approach but is cleaner and easy to understand
```
 map<int,int>events;
    MyCalendar() {   
    }
    bool book(int start, int end) {
        auto next = events.upper_bound(start);
        if(next != events.end() &&   (*next).second < end)return false;
        events.insert({end,start});
        return true;
    }
```
