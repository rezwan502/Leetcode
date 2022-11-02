class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string, bool> isValid;
        unordered_map<string, bool> isTaken;
        for(auto x: bank) isValid[x] = true;
        
        queue<string>Q;
        Q.push(start);
        
        int step = 0;
        while(!Q.empty()) {
            int sz = Q.size();
            for(int i=0; i<sz; i++) {
                string temp = Q.front();
                Q.pop();
                if (temp == end) return step;
                for(int k=0; k<temp.length(); k++) {
                    string c_temp = temp;
                    for(int i='A'; i<='Z'; i++) {
                        c_temp[k] = (char) i;
                        if (isValid[c_temp] && !isTaken[c_temp]) {
                            isTaken[c_temp] = true;
                            Q.push(c_temp);
                        }
                    }
                }
            }
            step++;
        }
        
        return -1;
    }
};