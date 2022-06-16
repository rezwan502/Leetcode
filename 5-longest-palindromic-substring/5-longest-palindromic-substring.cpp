class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.length();
        
        string res = "";
        int resLen = 0;
        
        for(int i=0; i<sz; i++){
            int start = i;
            int end = i;
            
            while((start>=0 && end<sz) && s[start] == s[end]){
                if(end-start+1 > resLen){
                    res = s.substr(start, end-start+1);
                    resLen = end-start;
                }
                start--;
                end++;
            }
            
             start = i;
             end = i+1;
            
            while((start>=0 && end<sz) && s[start] == s[end]){
                if(end-start+1 > resLen){
                    res = s.substr(start, end-start+1);
                    resLen = end-start;
                }
                start--;
                end++;
            }
        }
        
       // cout << res << endl;
        
        return res;
    }
};