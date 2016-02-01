#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

typedef pair<long long, long long> point;

set<point>X[100010], Y[100010];
set<point>::iterator it;
long long ans[100010];
priority_queue<point>Q;
vector<long long>ox, oy;
vector<point>robots;
vector<char>dir;
vector<int>del;
char buf[10];
int n, t;

int main() {
	scanf("%d%d", &n, &t);
	for(int i = 0; i < n; i++) ans[i] = t + 1;
	for(int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d%s", &x, &y, buf);
		robots.push_back(make_pair(x, y));
		dir.push_back(buf[0]);
		ox.push_back(x);
		oy.push_back(y);
	}
	sort(ox.begin(), ox.end());
	sort(oy.begin(), oy.end());
	ox.resize(unique(ox.begin(), ox.end()) - ox.begin());
	oy.resize(unique(oy.begin(), oy.end()) - oy.begin());
	for(int i = 0; i < n; i++) {
		robots[i].first = lower_bound(ox.begin(), ox.end(), robots[i].first) - ox.begin();
		robots[i].second = lower_bound(oy.begin(), oy.end(), robots[i].second) - oy.begin();
	}
	for(int i = 1; i < n; i++) {
		X[robots[i].first].insert(make_pair(robots[i].second, i));
		Y[robots[i].second].insert(make_pair(robots[i].first, i));
	}
	Q.push(make_pair(0, 0));
	while(Q.size()) {
		point p = Q.top();
		int x = p.second; long long T = -p.first;
		Q.pop();
		del.clear();
		if(dir[x] == 'L' || dir[x] == 'R') {
			it = Y[robots[x].second].lower_bound(make_pair(robots[x].first, -1));
			if(dir[x] == 'R') {
				while(it != Y[robots[x].second].end()) {
					del.push_back(it->second);
					it++;
				}
			}
			else {
				while(it != Y[robots[x].second].end()) {
					if(it->first <= robots[x].first)
					del.push_back(it->second);
					if(it == Y[robots[x].second].begin()) break;
					it--;
				}
			}
		}
		else {
			it = X[robots[x].first].lower_bound(make_pair(robots[x].second, -1));
			if(dir[x] == 'U')  {
				while(it != X[robots[x].first].end()) {
					del.push_back(it->second);
					it++;				
				}
			}
			else {
				while(it != X[robots[x].first].end()) {
					if(it->first <= robots[x].second)
					del.push_back(it->second);
					if(it == X[robots[x].first].begin()) break;
					it--;				
				}
			}
		}
		for(int i = 0; i < del.size(); i++) {
			int v = del[i];
			ans[v] = T + abs(ox[robots[v].first] - ox[robots[x].first]) + abs(oy[robots[v].second] - oy[robots[x].second]);
			Q.push(make_pair(-ans[v], v));
			X[robots[v].first].erase(X[robots[v].first].find(make_pair(robots[v].second, v)));
			Y[robots[v].second].erase(Y[robots[v].second].find(make_pair(robots[v].first, v)));
		}
	}
	ans[0] = 0;
	for(int i = 0; i < n; i++) {
		long long del = max(0LL, (long long)t - ans[i]);
		if(dir[i] == 'R') printf("%lld %lld\n", (long long)ox[robots[i].first] + del, (long long)oy[robots[i].second]);
		if(dir[i] == 'L') printf("%lld %lld\n", (long long)ox[robots[i].first] - del, (long long)oy[robots[i].second]);
		if(dir[i] == 'U') printf("%lld %lld\n", (long long)ox[robots[i].first], (long long)oy[robots[i].second] + del);
		if(dir[i] == 'D') printf("%lld %lld\n", (long long)ox[robots[i].first], (long long)oy[robots[i].second] - del);
	}
 	return 0;
}
