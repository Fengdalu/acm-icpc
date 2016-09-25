#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partition(vector<int> & nums, int l, int r) {//[l, r]
	if(l >= r) return l;
	int i, j;
	int val = nums[l];
	i = l; j = r;
	while(1) {
	    while(i < j && nums[j] > val) --j;
	    if(i < j) {
		nums[i] = nums[j];
		i++;
	    }
	    while(i < j && nums[i] < val) ++i;
	    if(i < j) {
		nums[j] = nums[i];
		j--;
	    }
	    if(i >= j) break;
	}
	nums[i] = val;
	return i;
    }
    int getKth(vector<int> & nums, int k) {
	int p, l = 0, r = nums.size() - 1;
	while(l < r) {
	    p = partition(nums, l, r);
	    if(p - l >= k) {
		r = p - 1;
	    }
	    else if(p - l + 1 == k) return nums[p];
	    else {
		k -= p - l + 1;
		l = p + 1;
	    }
	}
	return nums[l];
    }
    int countNum(vector<int> & nums, int x) {
	int ret = 0;
	for(int i = 0; i < nums.size(); ++i) if(nums[i] == x) ret++;
	return ret;
    }
    vector<int> majorityElement(vector<int>& nums) {
	vector<int> ret = vector<int>();
	if(nums.size() == 0) return ret;
	int kth, cnt;
	kth = getKth(nums, nums.size() / 3);
	cnt = countNum(nums, kth);
	if(cnt > nums.size() / 3) {
	    if(ret.size() == 0 || ret[ret.size() - 1] != kth) ret.push_back(kth);
	}
	kth = getKth(nums, nums.size() / 2);
	cnt = countNum(nums, kth);
	if(cnt > nums.size() / 3) {
	    if(ret.size() == 0 || ret[ret.size() - 1] != kth) ret.push_back(kth);
	}
	kth = getKth(nums, nums.size() - nums.size() / 3);
	cnt = countNum(nums, kth);
	if(cnt > nums.size() / 3) {
	    if(ret.size() == 0 || ret[ret.size() - 1] != kth) ret.push_back(kth);
	}
	return ret;
    }
};

int main() {
    vector<int> g, f;
    int i;
    Solution s;
    g.push_back(1);
    g.push_back(2);
    f = s.majorityElement(g);
    for(i = 0; i < f.size(); ++i) printf("%d ", f[i]); puts("");
    return 0;
}
