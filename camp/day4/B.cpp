#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define Maxn 31

vector<int>g[Maxn];
int dp[1 << 20];
int c[Maxn];
vector<int>white, black;
vector<int>nodes;
int dominated[Maxn];
int id[Maxn];
int v0, v1;
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		int x, y; 
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	deque<int>Q;
	memset(c, -1, sizeof c);
	for(int i = 1; i <= n; i++) if(c[i] == -1) {
		c[i] = 0;
		Q.push_back(i);
		while(Q.size()) {
			int x = Q.front();
			Q.pop_front();
			for(int i = 0; i < g[x].size(); i++) if(c[g[x][i]] == -1) {
				c[g[x][i]] = c[x] ^ 1;
				Q.push_back(g[x][i]);
			}
		}
	}
	for(int i = 1; i <= n; i++) v1 += c[i];
	v0 = n - v1;
	if(v0 > v1) {
		swap(v0, v1);
		for(int i = 1; i <= n; i++) c[i] ^= 1;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) if(c[i]) black.push_back(i); else white.push_back(i);
	for(int mask = 0; mask < (1 << v0); mask++) {
		nodes.clear();

		int m = 0;
		for(int i = 0; i < v0; i++) id[white[i]] = -1;
		for(int i = 0; i < v0; i++) 
			if(1 << i & mask) nodes.push_back(white[i]);
			else id[white[i]] = m++;
		for(int i = 0; i < v1; i++) dominated[black[i]] = false;
		for(int i = 0; i < nodes.size(); i++) {
			int v = nodes[i];
			for(int j = 0; j < g[v].size(); j++) dominated[g[v][j]] = true;
		}

		for(int i = 0; i < (1 << m); i++) dp[i] = 0;
		dp[0] = 1;
		for(int i = 0; i < v1; i++) { 
			int v = black[i];
			int cover = 0;
			for(int j = 0; j < g[v].size(); j++) {
				if(id[g[v][j]] != -1) cover |= (1 << id[g[v][j]]);
			}
			for(int j = (1 << m) - 1; j >= 0; j--) {
				int w = dp[j];
				dp[j] = 0;
				if(dominated[v]) dp[j] += w;
				dp[j | cover] += w;
			}
		}
		ans += dp[(1 << m) - 1];
	}
	printf("%d\n", ans);
	return 0;
}
