class Solution {
public:
    bool getDiff(string &str, string &temp) {
        int diff = 0;
        for(int i=0; i<8; i++) {
            if(str[i] != temp[i]) diff++;
        }
        return diff == 1;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string, bool> isValid;
        
        queue<pair<string,int>>Q;
        Q.push({start,0});
        isValid[start] = true;
        
        while(!Q.empty()) {
            int sz = Q.size();
            for(int i=0; i<sz; i++) {
                pair<string,int> temp = Q.front();
                Q.pop();
                if (temp.first == end) return temp.second;
                for(auto x: bank) {
                    if(isValid.find(x) == isValid.end() && getDiff(x,temp.first)) {
                        Q.push({x,temp.second + 1});
                        isValid[x] = true;
                    }
                }
            }
        }
        
        return -1;
    }
};