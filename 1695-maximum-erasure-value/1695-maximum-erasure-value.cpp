class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int start = 0;
        int end = 0;
        int ans = -1;
        int sum = 0;
        
        unordered_map<int,int> seen;
        
        while(end < n){
            sum += nums[end];
            seen[nums[end]]++;
            
            int deduct = 0;
            while(seen[nums[end]] > 1){
                deduct += nums[start];
                seen[nums[start]] -= 1;
                start++;
            }
            
            end++;
            sum -= deduct;
            
            ans = max(ans, sum);
        }
        
        return ans;
    }
};