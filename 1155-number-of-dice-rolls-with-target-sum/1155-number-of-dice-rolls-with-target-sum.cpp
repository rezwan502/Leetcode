class Solution {
public:
    
    int MOD = 1e9+7;
    int dp[32][1002];
    
    int findPossibleWays(int dice, int numbers, int target, int res = 0) {
        if ( dice == 0 && target == 0) return 1;
        if (dice <= 0 || target <= 0) return 0;
        
        if (dp[dice][target] != -1) return dp[dice][target];
        
        for(int i = 1; i<=numbers; i++) {
            res = (res + findPossibleWays(dice-1,numbers,target-i) % MOD) % MOD;
        }
        return dp[dice][target] = res;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof dp);
        return findPossibleWays(n,k,target);
    }
};