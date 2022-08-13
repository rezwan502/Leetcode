class Solution {
public:
    
    bool checkString(unordered_map<string,int> stringMap, string str, int wordLen){  
        for(int j=0; j<str.length(); j+=wordLen) {
            string temp = str.substr(j,wordLen);
            if(stringMap.find(temp) != stringMap.end()){
                if(--stringMap[temp] == -1) return false;
            } else {
                return false;
            }
        }
        return true;
    }
    
    
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int wordLen = words[0].length();
        int sLen = s.length();
        int windowLen = wordLen * words.size();
        
        unordered_map<string, int> stringMap;
        
        for(int i=0; i<words.size(); i++) {
            stringMap[words[i]]++;
        }
        
        for(int i=0; i<=sLen - windowLen; i++) {
            if(checkString(stringMap, s.substr(i,windowLen), wordLen)) {
                res.push_back(i);
            }        
        }
        
        return res;
    }
};