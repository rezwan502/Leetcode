class Solution {
public:
    
    string convert_string(string pattern){
        string str = "";
        unordered_map<char,int> mp;
        int cnt = 1;
        mp[pattern[0]] = cnt;
        str += to_string(mp[pattern[0]]) + '-';
        
        for(int i=1; i<pattern.length(); i++){
            if(!mp[pattern[i]]) mp[pattern[i]] = ++cnt;
            str += to_string(mp[pattern[i]]) + '-';
        }    
        return str;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        // Intution: As we can convert char to any char. we just need to find a pattern of distinct char 
        // words:
        // abc -> 1-2-3
        // deq -> 1-2-3
        // mee -> 1-2-2
        // aqq -> 1-2-2
        // dkd -> 1-2-1
        // ccc -> 1-1-1
        // pattern:
        // abb -> 1-2-2
        
        // Here we can see that "mee", "aqq" have same pattern as abb.
        
        string valid = convert_string(pattern);
        vector<string> ans;
        
        for(int i=0; i<words.size(); i++){
            if(valid == convert_string(words[i])){
                ans.push_back(words[i]);
            }
        }
        
        return ans;
    }
};