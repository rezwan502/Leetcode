class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        
        deque<int> maxIdx;
        maxIdx.push_back(0);
        
        for(int i=1; i<n; i++){
            if(maxIdx.front() + k < i) maxIdx.pop_front();
            nums[i] += nums[maxIdx.front()];
            while(!maxIdx.empty() && nums[maxIdx.back()] < nums[i]){
                maxIdx.pop_back();
            }
            maxIdx.push_back(i);
        }
        
        return nums[n-1];
    }
};