class Solution {
public:
    
    struct cmp{
        bool operator()(int a, int b)const{
            return a > b;
        }
    };
    
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        priority_queue<int, vector<int>, cmp>pq;

        int n = heights.size();
        
        for(int i=1; i<n; i++){
            int diff = heights[i] - heights[i-1];
            if(diff > 0){
                if(pq.size() < ladders){
                    pq.push(diff);
                }else{
                    int cur = diff;
                    if(pq.size() > 0 && pq.top() < diff){
                        cur = pq.top();
                        pq.pop();
                        pq.push(diff);
                    }
                    if(bricks-cur>=0){
                        bricks -= cur;
                    }else{
                        return i-1;
                    }
                }
            }
        }
        
        return n-1;

    }
};