#include <bits/stdc++.h>
using namespace std;

  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
//------------------------Start Solution
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    bool cover(const Interval & a, const Interval & b) {
	if(a.start <= b.start && a.end >= b.start) return true;
	if(b.start <= a.start && b.end >= a.start) return true;
	return false;
    }
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
	vector<Interval> ret;
	Interval tp = newInterval;
	if(intervals.size() == 0) {
	    ret.push_back(newInterval);
	    return ret;
	}
	int i, flag = 0;
	for(i = 0; i < intervals.size(); ++i) {
	    if(cover(intervals[i], newInterval)) {
		tp.start = min(intervals[i].start, newInterval.start);
		tp.end = max(intervals[i].end, newInterval.end);
		break;
	    }
	    else if(intervals[i].end < newInterval.start){
		ret.push_back(intervals[i]);
	    }
	    else if(intervals[i].start > newInterval.end) {
		if(!flag) {
		    ret.push_back(newInterval);
		    flag = 1;
		}
		ret.push_back(intervals[i]);
	    }
	}
	if(i < intervals.size()) {
	    for(++i ; i < intervals.size(); ++i) {
		if(intervals[i].start <= tp.end) {
		    tp.end = max(tp.end, intervals[i].end);
		}
		else break;
	    }
	    ret.push_back(tp);
	    for( ; i < intervals.size(); ++i) {
		ret.push_back(intervals[i]);
	    }
	}
	else {
	    if(!flag)ret.push_back(tp);
	}
	return ret;
    }
};

//-------------------------End Solution

int main() {
    Solution s;
    return 0;
}
