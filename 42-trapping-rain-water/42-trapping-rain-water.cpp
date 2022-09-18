class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        vector<int> maxLeft(len,0);
        vector<int>maxRight(len,0);
        
        maxLeft[0] = height[0];
        for(int i=1; i<height.size(); i++) {
            maxLeft[i] = max(height[i],maxLeft[i-1]);
        }
        
        maxRight[len-1] = height[len-1];
        for(int i=len-2; i>=0; i--) {
            maxRight[i] = max(height[i],maxRight[i+1]);
        }
        
        int water = 0;
        for(int i=0; i<len; i++) {
            water += min(maxLeft[i],maxRight[i]) - height[i];
        }
        
        return water;
    }
};