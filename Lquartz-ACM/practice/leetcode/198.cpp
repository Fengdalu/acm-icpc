class Solution {
public:
    int rob(vector<int>& nums) {
	if(nums.size() == 0) return 0;
	int dmax = -1;
	vector<int> g0, g1;
	g0.push_back(0);
	g1.push_back(nums[0]);
	for(int i = 1; i < nums.size(); ++i) {
	    g0.push_back(max(g0[i - 1], g1[i - 1]));
	    g1.push_back(g0[i - 1] + nums[i]);
	}
	dmax = max(g0[nums.size() - 1], g1[nums.size() - 1]);
	return dmax;
    }
};
