class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> mSet;
        string str;
        
        int len = s.length();
        
        for(int i=0; i<=len-k;i++){
            str = s.substr(i,k);
            mSet.insert(str);
        }
        
        int check = mSet.size();
        int limit = 1 << k;
        
        if(check == limit){
          return true;  
        } 
        return false;
    }
};