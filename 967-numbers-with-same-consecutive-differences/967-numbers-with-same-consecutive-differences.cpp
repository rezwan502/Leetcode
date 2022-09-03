class Solution {
public:
    
    void rec(int digit, int n, int k, vector<int> &ans, string str) {
        if(str.length() == n) {
            int num = stoi(str);
            ans.push_back(num);
            return;
        }
        
        if(digit + k <=9) {
            rec(digit+k, n, k, ans, str + to_string(digit+k));
        } 
        if (digit - k >= 0 && k>0) {
            rec(digit-k, n, k, ans, str + to_string(digit-k));
        }
    }
    
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i=1; i<=9; i++) {
            string str = to_string(i);
            rec(i, n, k, ans, str);
        }
        return ans;
    }
};