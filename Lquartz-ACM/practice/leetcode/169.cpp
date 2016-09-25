class Solution {
public:
    int majorityElement(vector<int>& nums) {
	int i, j, ret = -1, p = -1;
	//sort(nums.begin(), nums.end());
	for(i = 0; i < nums.size(); ) {
	    for(j = i + 1; j < nums.size() && nums[j] == nums[i]; ++j);
	    if(j - i > p) {
		ret = nums[i];
		p = j - i;
	    }
	    i = j;
	}
	return ret;
    }
};
