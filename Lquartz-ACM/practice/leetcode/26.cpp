class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
	if(nums.size() == 0) return 0;
	int i, j;
	for(i = 1, j = 0; i < nums.size(); ++i) {
	    if(nums[i] == nums[j]) continue;
	    else {
		nums[++j] = nums[i];
	    }
	}
	return j + 1;
    }
};
