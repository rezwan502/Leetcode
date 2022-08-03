class MyCalendar {
public:
    
    set<pair<int,int>> startTime;
    
    MyCalendar() {
        startTime.clear();
    }
    
    bool book(int start, int end) {
        
        for(auto it: startTime){
            if(start < it.second  &&   it.first < end){
                return false;
            }
        }
        
        startTime.insert({start,end});
        
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */