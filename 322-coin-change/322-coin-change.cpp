class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        
        if(amount == 0) return 0;
        
        for(int i=0; i<=amount; i++) dp[i] = amount+1;
        dp[0] = 0;
        int sz = coins.size();
        
        for(int i=0; i<=amount; i++){
            for(int j=0; j<sz; j++){
                int idx = i - coins[j];
                if(idx >= 0){
                    dp[i] = min(dp[i],dp[idx] + 1);
                    
                }    
            }   
        }
        
        if(dp[amount] == amount+1) return -1;
        return dp[amount];    
    }
};