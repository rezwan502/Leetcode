class Solution {
public:
    int sz1,sz2,sz3;
    
    
    bool isPossible(string s1, string s2, string s3,int i,int j,int k, int dp[201][201]){
        
        if(i == sz1 && j == sz2 &&  k == sz3) return true;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        bool f1 = false, f2 = false;
        
        if(i < sz1 && s1[i]==s3[k]){
            f1 = isPossible(s1,s2,s3,i+1,j,k+1,dp);
        }
        if(j < sz2 && s2[j]==s3[k]){
            f2 = isPossible(s1,s2,s3,i,j+1,k+1,dp);
        }
        
        return dp[i][j] = f1 || f2;
    }
 
    bool isInterleave(string s1, string s2, string s3) {
        sz1 = s1.length();
        sz2 = s2.length();
        sz3 = s3.length();
        if(sz1 + sz2 != sz3) return false;
        
        int dp[201][201];
        
        for(int i=0; i<=sz1; i++){
            for(int j=0; j<=sz2; j++){
                dp[i][j] = -1;
            }
        }
        
        return isPossible(s1,s2,s3,0,0,0,dp);
    }
};