#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output = vector<int>(nums.size());
	int i;
	if(nums.size() == 0) return output;
	output[0] = (1);
	for(i = 1; i < nums.size(); ++i) {
	    output[i] = (output[i - 1] * nums[i - 1]);
	}
	int cur = 1;
	for(i = nums.size() - 2; i >= 0; --i) {
	    cur = cur * nums[i + 1];
	    output[i] = output[i] * cur;   
	}
	return output;
    }
};

int main() {

    return 0;
}
