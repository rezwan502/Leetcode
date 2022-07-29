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
        
        //cout << "str: " << str << endl;
        
        return str;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
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