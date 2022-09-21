class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int totalSum = 0;
        for (auto x: nums) {
            if (x%2 == 0) totalSum += x;
        }
        
        vector<int> ans;
        
        for (auto x: queries) {
            int val = x[0];
            int idx = x[1];
            
            if (nums[idx] % 2 == 0 ) totalSum -= nums[idx];
            
            nums[idx] += val;
            
            if (nums[idx] % 2 == 0) totalSum += nums[idx];
            
            ans.push_back(totalSum);
        }
        
        return ans;
    }
};