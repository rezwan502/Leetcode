class Solution {
public:
    vector<int> ans;
    void merge(int l, int mid, int r, vector<pair<int, int>>& nums, vector<pair<int, int>> &temp) {
        int i = l;
        int j = mid + 1;
        int k = l;
        while(i <= mid && j <= r) {
            if(nums[i].first > nums[j].first) {
                ans[nums[i].second] += (r-j+1);
                temp[k++] = nums[i++];
            }
            else    temp[k++] = nums[j++];
        }
        while(i <= mid) temp[k++] = nums[i++];
        while(j <= r) temp[k++] = nums[j++];
        for(int ii = l; ii <= r; ++ii)  nums[ii]= temp[ii];
    }
    void merge_sort(int l, int r, vector<pair<int, int>>& nums, vector<pair<int, int>> &temp) {
        if(l == r)  return;
        int mid = (l + r) >> 1;
        merge_sort(l, mid, nums, temp);
        merge_sort(mid + 1, r, nums, temp);
        merge(l, mid, r, nums, temp);
    }
    vector<int> countSmaller(vector<int>& v) {
        vector<pair<int, int>> nums;
        int i = 0;
        for(auto it: v) nums.push_back({it, i++});
        
        int n = nums.size();
        ans.resize(n);
        vector<pair<int, int>> temp(n);
        merge_sort(0, n - 1, nums, temp);
        return ans;
    }
};