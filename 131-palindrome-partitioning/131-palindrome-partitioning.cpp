class Solution {
public:
    
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    
    void partition(int idx, int len, string s, vector<string> pat, vector<vector<string>>& ans){
        if(idx == len){
            ans.push_back(pat);
            return;
        }
        
        for(int i=idx; i<len; i++){
            if(isPalindrome(s, idx, i)){
                pat.push_back(s.substr(idx,i - idx + 1));
                partition(i+1,len,s,pat,ans);
                pat.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> pat;
        int n = s.length();
        // recursion
        partition(0,n,s,pat,ans);
        // vector to store answer
        return ans;
    }
};