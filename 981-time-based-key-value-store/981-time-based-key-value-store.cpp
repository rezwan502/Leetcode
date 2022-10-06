class TimeMap {
public:
    
    unordered_map<string,vector<pair<string,int>>> timeMapDS;
    
    TimeMap() {
        timeMapDS.clear();
    }
    
    void set(string key, string value, int timestamp) {
        timeMapDS[key].push_back({value,timestamp});
    }
    
    int binarySearch(string key, int timestamp) {
        int low = 0, high = timeMapDS[key].size()-1;
        int ans = -1;
        while(low<=high) {
            int mid = (low + high)/2;

            if(timeMapDS[key][mid].second == timestamp) {
                return mid;
            }
            
            if(timeMapDS[key][mid].second < timestamp) {
                low = mid+1;
                ans = mid;
            } else {
                high = mid-1;
            }
        }
        
        return ans;
    }
    
    string get(string key, int timestamp) {
        int idx = binarySearch(key,timestamp);
        if(idx != -1) {
            return timeMapDS[key][idx].first;
        }
        return ""
;    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */