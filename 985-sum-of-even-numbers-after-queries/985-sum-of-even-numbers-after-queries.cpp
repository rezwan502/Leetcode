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
            int temp = nums[idx];
         
            nums[idx] += val;
            
            if(nums[idx] % 2 == 0) {
                if ( temp % 2 != 0) {
                    temp = 0;
                }
                totalSum = (totalSum - temp) + nums[idx];
                ans.push_back(totalSum);
            } else if (temp % 2 == 0 ) {
                totalSum = totalSum - temp;
                ans.push_back(totalSum);
            } else {
                ans.push_back(totalSum);
            }
        }
        
        return ans;
    }
};