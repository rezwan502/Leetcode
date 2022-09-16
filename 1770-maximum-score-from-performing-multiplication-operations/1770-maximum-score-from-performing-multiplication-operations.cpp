class Solution {
public:
   int n, m;
   int solve(int l, vector<int>& nums, int i, vector<int>& mult, vector<vector<int>> &dp)  
    {               
        if(i == m)
            return 0;
       
        if(dp[l][i] != INT_MIN) return dp[l][i];
       
		int r = (n-1)-(i-l);
        
		return dp[l][i] = max(nums[l]*mult[i] + solve(l+1, nums, i+1, mult, dp), nums[r]*mult[i] + solve(l, nums, i+1, mult, dp));
    }
    
    int maximumScore(vector<int>& nums, vector<int>& mult) 
    {   // ith operation = nums[start or end]*mult[i]
        n = nums.size();
        m = mult.size();
        
        vector<vector<int>> dp(m, vector<int>(m, INT_MIN));
        
        return solve(0, nums, 0, mult, dp);
    }
};