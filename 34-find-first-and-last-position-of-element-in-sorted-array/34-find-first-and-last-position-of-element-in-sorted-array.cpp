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
    
    if(nums.size() == 0) return {-1,-1};
    
	int min = -1;
	int max = -1;

	//max = customBinarySearch(nums, target, "left");	
	//min = customBinarySearch(nums, target, "right");
    
    auto min_it = lower_bound(nums.begin(), nums.end(), target);
    
    
    if(min_it != nums.end() && *min_it == target){
        min = min_it - nums.begin();
    }
    
   // cout << min_it -  nums.end() << endl;
    
    auto mx_it = upper_bound(nums.begin(), nums.end(), target);
    
    cout << nums.end() - mx_it << endl;
    
    
    if(mx_it != nums.end()){
        if(mx_it == nums.begin() && *mx_it != target){
            max = -1;
        }else if(nums.end() - mx_it == 1 && nums.size() == 1 && *mx_it == target){
            max = 0;
        }
        else if (*(mx_it - 1) == target){
            max =  mx_it - nums.begin() - 1;
        }
    }else{
        if(*(mx_it-1) == target){
            max = nums.end() - nums.begin() - 1;
        }
    }
    
	vector<int>ans;
	ans.push_back(min);
	ans.push_back(max);

	return ans;
}

};