#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class FoxAndChess {
public:
	string ableToMove(string, string);
};

string FoxAndChess::ableToMove(string begin, string target) {
	vector<pair<int, int> > a, b;
	for(int i = 0; i < begin.size(); i++) if(begin[i] == 'L') a.push_back(make_pair(i, -1)); else if(begin[i] == 'R') a.push_back(make_pair(i, 1));
	for(int i = 0; i < target.size(); i++) if(target[i] == 'L') b.push_back(make_pair(i, -1)); else if(target[i] == 'R') b.push_back(make_pair(i, 1));
	if(a.size() != b.size()) return "Impossible";
	if(a.size() == 0) return "Possible";
	int cur = a[0].first;
	for(int i = 0; i < a.size(); i++) {
		cout << cur << endl;
		//if(a[i].first < cur) return "Impossible";
		if(a[i].second == -1) {
			if(b[i].second != -1) return "Impossible";
			else if(b[i].first > a[i].first) return "Impossible";
		}
		if(a[i].second == 1) {
			if(b[i].second != 1) return "Impossible";
			else if(b[i].first < a[i].first) return "Impossible";
		}
		cur = b[i].first;
	}
	return "Possible";
}


//Powered by [KawigiEdit] 2.0!
