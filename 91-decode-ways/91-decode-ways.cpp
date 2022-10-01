/*
class Solution {
public:
    
    int rec(int idx, string s, vector<int> dp) {
        if(s[idx] == '0') {
            return 0;
        }
        
        if(idx == s.size()) {
            return 1;
        }
        
        if (dp[idx] != -1) {
            return dp[idx];
        }
        
        int one = rec(idx+1,s,dp);
        int two=0;
        if(idx < s.size() -1 && (s[idx] == '1' || s[idx] == '2' && s[idx+1] <= '6')) {
           two+=rec(idx+2,s,dp);
        }
        return dp[idx] = one+two;
    }
    
    int numDecodings(string s) {
        vector<int> dp(s.length()+1,-1);
        return rec(0,s,dp);
    }
}; */

class Solution {
public:
    int find(int i,string s,vector<int>&dp)
    {
        if(s[i]=='0')
        {
            return 0;
        }
        if(i==s.size())
        {
            return 1;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int one = find(i+1,s,dp);
        int two=0;
        if(i < s.size() -1 && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6'))
           {
           two+=find(i+2,s,dp);
           }
           return dp[i] = one+two;
    }
    int numDecodings(string s) {
    vector<int>dp(s.size()+1,-1);
    return find(0,s,dp);
    
    }
};