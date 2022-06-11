class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        int sz = nums.size();
        
        for(int n: nums){
            total += n;
        }
        
        int rem = total - x;
        
        if(rem < 0) return -1;
        if(rem == 0) return sz;
        
        int start = 0;
        int end = 0;
        
        int cur = nums[end];
        int len = -1;
        
        while(end < sz){
            //cout << "Cur: " << cur << " " << start << " " << end << endl;
            
            if(cur == rem){
               len = max(len, end-start+1);
               cur -= nums[start];
               start++; 
            }else if(cur > rem){
                while(cur > rem){
                    cur -= nums[start];
                    start++;
                } 
            }
            else{
                end++;
                cur += nums[end];
            }
        }
        
        return len == -1 ? -1 : sz - len;
    }
};