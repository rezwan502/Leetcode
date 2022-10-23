class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> track(nums.size()+1, 0);
        for(auto x: nums) {
            track[x]++;
        }
        
        vector<int>ans;
        
        for (int i=1; i<track.size(); i++) {
            if (track[i] == 2) {
                ans.push_back(i);
            }
        }
        
        for (int i=1; i<track.size(); i++) {
            if (track[i] == 0) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};