#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	multimap<int,int> mp;
	multimap<int,int>::iterator IT;
	int i1 = -1, i2 = -1;
	int i;
	for(i = 0; i < nums.size(); ++i) mp.insert(make_pair(nums[i], i));
	for(i = 0; i < nums.size(); ++i) {
	    if((IT = mp.find(target - nums[i])) != mp.end()) {
		if(target == nums[i] * 2 && mp.count(nums[i]) == 2) {
		    i1 = IT->second;
		    IT++;
		    i2 = (IT)->second;
		    break;
		}
		else if(target != nums[i] * 2){
		    i1 = i;
		    i2 = IT->second;
		    break;
		}
	    }
	}
	if(i1 > i2) swap(i1, i2);
	i1++; i2++;
	vector<int> ret;
	ret.push_back(i1);
	ret.push_back(i2);
	return ret;
    }
};

int main() {
    Solution s;
    vector<int> g, f;
    int i;
    g.push_back(3);
    g.push_back(2);
    g.push_back(4);
    f = s.twoSum(g, 6);
    for(i = 0; i < f.size(); ++i) printf("%d ", f[i]); puts("");
    return 0;
}
