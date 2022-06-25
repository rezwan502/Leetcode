class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int dup = 0;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            if(nums[i] == nums[0]) dup++;  
            if(nums[i] == nums[n-1]) dup++;
        }
        
        return (n-dup) > 0 ? n-dup : 0;
    }
};