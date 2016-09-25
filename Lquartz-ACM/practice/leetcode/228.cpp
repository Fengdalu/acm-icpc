#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i, j;
	vector<string> ret;
        for(i = 0; i < nums.size(); ) {
	    for(j = i + 1; j < nums.size() && nums[j] == nums[j - 1] + 1; ++j);
	    ostringstream ss;
	    ss << nums[i];
	    if(j > i + 1) {
		ss << "->" << nums[j - 1];
	    }
	    string str = ss.str();
	    ret.push_back(str);
	    i = j;
        }
	return ret;
    }
};

int main() {
    vector<int> g;
    g.push_back(0);
    g.push_back(1);
    g.push_back(2);
    g.push_back(4);
    g.push_back(5);
    g.push_back(7);
    g.push_back(10);
    Solution s;
    vector<string> f = s.summaryRanges(g);
    for(int i = 0; i < f.size(); ++i) cout << f[i] << endl;
    return 0;
}
