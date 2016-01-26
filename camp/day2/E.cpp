#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <vector>
using namespace std;
#define AA first
#define BB second 
#define PII pair<int, int>
#define MP(x, y) make_pair(x, y)
#define SZ size()
#define OP begin()
#define ED end()

int fa[N];
set <PII> s;
int x[N], y[N], l[N];
vector<int>H;
vector<int>::iterator l, r;

int main() {
	int T; scanf("%d", &T);
	for(int _C = 1; _C <= T; _C++) {
		int n, m;
		s.clear();	
		H.clear();
		for(int i = 0; i < m; i++) scanf("%d%d%d", &x[i], &y[i], &l[i]);
		memset(fa, -1, sizeof fa);
		for(int i = 0; i < m; i++) {
			l = s.lower_bound(s.OP, s.ED; MP(x[i], x[i] + l[i] - 1));
			r = s.lower_bound(s.OP, s.ED, MP(y[i], y[i] + l[i] - 1));
		}

	}
	return 0;
}
