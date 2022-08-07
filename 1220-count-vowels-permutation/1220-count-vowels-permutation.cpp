class Solution {
public:
    unordered_map<char, vector<char>> m;
    int MOD = 1e9+7;
    
    int helper(int n, int i, char c, vector<vector<long long>> &dp){
        if(i > n) return 0;
        if(i==n){
            switch(c){
                case 'a':
                    return 1;
                case 'e':
                    return 2;
                case 'i':
                    return 4;
                case 'o':
                    return 2;
                case 'u':
                    return 1;
                default:
                    return 5;
            }
        }
        
        int idx = c - 'a';
        
        if(dp[i][idx] != -1) return dp[i][idx];
        
        long long ans = 0;
        
        for(auto x: m[c]){
            ans += (helper(n,i+1,x,dp)) % MOD;
        }
        
        return dp[i][idx] = ans % MOD;
    }
    
    
    int countVowelPermutation(int n) {
        m['c'] = {'a','e','i','o','u'};
        m['a'] = {'e'};
        m['e'] = {'a','i'};
        m['i'] = {'a','e','o','u'};
        m['o'] = {'i','u'};
        m['u'] = {'a'};
        
        vector<vector<long long> > dp(vector<vector<long long>>(n+1,vector<long long>(27,-1)));
        
        return helper(n,1,'c',dp);
        
    }
};