class Solution {
public:
    
    int MOD = 1e9+7;
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<int,long> mp;
        
        sort(arr.begin(), arr.end());
        
        mp[arr[0]] = 1;
        
        for(int i=1; i<arr.size(); i++){
            long cnt = 1;
            
            for(auto x: mp){
                int ele = x.first;
               if(arr[i] % ele == 0 && mp.find(arr[i]/ele) != mp.end()){
                    cnt += mp[ele] * mp[arr[i]/ele];
                }
            }
            
            mp[arr[i]] = cnt;
        }
        
        long ans = 0;
        for(auto x: mp){
            ans = (ans + x.second) % MOD;
        }
        
        return ans;
    }
};