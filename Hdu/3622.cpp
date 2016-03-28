#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

const int maxn = 210;
const int maxm = maxn * maxn;
int n;
int x[maxn], y[maxn];
int ind[maxn];
int to[maxm], nt[maxm];
int dfn[maxn], low[maxn];
int color[maxn];
int ncnt;
bool vis[maxn];
int num;
int cnt;
stack<int>s;


void add(int a, int b) {
	to[cnt] = b;
	nt[cnt] = ind[a];
	ind[a] = cnt++;
}

double sqr(double x) { return x * x; }

void tarjan(int x) {
	if(dfn[x] != 0) return;
	low[x] = dfn[x] = ++num;
	vis[x] = true;
	s.push(x);
	for(int k = ind[x]; k != -1; k = nt[k]) {
		tarjan(to[k]);
		if(vis[to[k]]) low[x] = min(low[x], low[to[k]]);
	}
	if(dfn[x] == low[x]) {
		ncnt++;
		while(true) {
			int p = s.top();
			s.pop();
			color[p] = ncnt;
			vis[p] = false;
			if(p == x) break;
		}
	}
}
int main() {
	while(~scanf("%d", &n))	 {
		for(int i = 0; i < n; i++) scanf("%d%d%d%d", &x[i], &y[i], &x[i + n], &y[i + n]);
		double l = 0, r = 1e9;
		while(fabs(l - r) > 1e-4) {
			double mid = (l + r) / 2;
			
			memset(ind, -1, sizeof(int) * 2 * n);
			cnt = 0;
			for(int i = 0; i < 2 * n; i++)
				for(int j = i + 1; j < 2 * n; j++) 
				if(sqr(2 * mid) > sqr(x[i] - x[j]) + sqr(y[i] - y[j])) {
					add(i, (j + n) % (2 * n));
					add(j, (i + n) % (2 * n));
				}
			memset(dfn, 0, sizeof(int) * (3 + 2 * n));
			memset(low, 0, sizeof(int) * (3 + 2 * n));
			memset(vis, 0, sizeof(bool) * (3 + 2 * n));
			num = 0;
			ncnt = 0;
			for(int i = 0; i < 2 * n; i++) 
			if(dfn[i] == 0) tarjan(i);

			bool flag = true;
			for(int i = 0; i < n; i++)
				if(color[i] == color[i + n])
					flag = false;
			if(flag) l = mid;
			else r = mid;
		}
		printf("%.2f\n", l);
	}
	return 0;
}

