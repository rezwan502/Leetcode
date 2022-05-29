class Solution {
public:

    int maxProduct(vector<string>& words) {
        int ans = 0;
        
        vector<int>v;
        
        for(auto str: words){
            int mask = 0;
            for(auto c: str){
                mask |= (1 << (c-'a'));
            }
            v.push_back(mask);
        }
        
        for(int i=0; i<words.size()-1; i++){
            for(int j=i+1; j<words.size(); j++){
                if((v[i] & v[j]) == 0){
                    int sz1 = words[i].length();
                    int sz2 = words[j].length();
                    ans = max(ans, sz1 * sz2);
                }
            }
        }
        return ans;
    }
};