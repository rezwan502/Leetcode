class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int ans = 0;
        int cur = startFuel;
        int i = 0;
        int n = stations.size();
        
        priority_queue<int> pq;
        
        while(cur < target) {
            while(i < n && stations[i][0] <= cur) {
                pq.push(stations[i][1]);
                i++;
            }
            
            if(pq.empty()) {
                return -1;
            }
            
            cur += pq.top();
            
            pq.pop();
            ans += 1;
        }
        
        return ans;
    }
};