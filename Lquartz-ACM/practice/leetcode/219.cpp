class Solution {
    vector<pair<int,int>> g;
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
	for(i = 0; i < nums.size(); ++i) g.push_back(make_pair(nums[i], i));
	sort(g.begin(), g.end());
	for(int i = 1; i < g.size(); ++i) {
	    if(g[i].first == g[i - 1].first && g[i].second - g[i - 1].second <= k) return true;
	}
	return false;
            
    }
};
