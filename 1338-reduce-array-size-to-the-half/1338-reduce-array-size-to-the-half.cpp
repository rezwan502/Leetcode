class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> ump;
        for(int i=0; i<arr.size(); i++) {
            ump[arr[i]]++;
        }
        
       priority_queue<int> pq;
        
        for(auto x: ump) {
            pq.push(x.second);
        }
        
        int minSz = arr.size() / 2;
        int cnt = 0;
        int sz = arr.size();
        
        while(!pq.empty()) {
            sz -= pq.top();
            pq.pop();
            cnt++;
            
            if(sz <= minSz) break;
            
        }
        
        return cnt;
    }
};