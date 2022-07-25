class Solution {
public:
    int customBinarySearch(vector<int> nums, int target, string side){
	int n = nums.size();
	int left = 0;
	int right = n-1;
	int ans = -1;

	while(left <= right){
		int mid = (left + right) / 2;
		
		if(nums[mid] == target){
			ans = mid;
			if(side == "left"){
				left = mid + 1;
			}else{
				right = mid - 1;
			}
		}
		else if(nums[mid] < target){
			left = mid + 1;
		}else if(nums[mid] > target){
			right = mid - 1;
		}
	}

	return ans;
}

vector<int> searchRange(vector<int>& nums, int target) {
	int min = -1;
	int max = -1;

	max = customBinarySearch(nums, target, "left");	
	min = customBinarySearch(nums, target, "right");	

	vector<int>ans;
	ans.push_back(min);
	ans.push_back(max);

	return ans;
}

};