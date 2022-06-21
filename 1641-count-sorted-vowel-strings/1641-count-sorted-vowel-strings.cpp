class Solution {
public:
    int countVowelStrings(int n) {
        int dp[5];
        
  
        for(int i=0; i<5; i++){
            dp[i] = 1;
        }
        
        for(int i=0; i<n; i++){
            for(int j=3; j>=0; j--){
                dp[j] += dp[j+1];
            }
        }
        
        return dp[0];
    }
};