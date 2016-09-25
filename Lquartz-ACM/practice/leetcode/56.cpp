#include <bits/stdc++.h>
using namespace std;

  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
//------------------------Start Solution
bool cmp(const Interval & a, const Interval & b) {
    if(a.start < b.start || (a.start == b.start && a.end > b.end)) return true;
    else return false;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
	vector<Interval> ret;
	Interval tp;
	if(intervals.size() == 0) return ret;
	sort(intervals.begin(), intervals.end(), cmp);
	tp = intervals[0];
	for(int i = 1; i < intervals.size(); ++i) {
	    if(tp.start == intervals[i].start) continue;
	    if(tp.end >= intervals[i].start) {
		tp.end = max(intervals[i].end, tp.end);
	    }
	    else {
		ret.push_back(tp);
		tp = intervals[i];
	    }
	}
	ret.push_back(tp);
	return ret;
    }
};


//-------------------------End Solution

int main() {
    Solution s;
    return 0;
}
