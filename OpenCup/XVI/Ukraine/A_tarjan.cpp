#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bitset>
using namespace std;

const int maxn = 10100;
const int maxm = 200010;

int ind[maxn];
int to[maxm], nt[maxm];
int dfn[maxn], low[maxn];
int color[maxn];
int number[maxn];
int vis[maxn];
int a[maxm], b[maxm];
int num;
int ncnt;
stack<int>s;
bitset<maxn>mask[maxn], ans[maxn];
int cnt;
int n, m;

void add(int a, int b) {
	to[cnt] = b;
	nt[cnt] = ind[a];
	ind[a] = cnt++;
}

void tarjan(int x) {
	if(dfn[x]) return;
	low[x] = dfn[x] = ++num;
	vis[x] = true;
	s.push(x);
	for(int k = ind[x]; k != -1; k = nt[k]) {
		tarjan(to[k]);
		if(vis[to[k]]) low[x] = min(low[x], low[to[k]]);
	}
	if(dfn[x] == low[x]) {
		while(true) {
			int p = s.top();
			s.pop();
			color[p] = ncnt;
			number[ncnt]++;
			vis[p] = false;
			if(p == x) break;
		}
		ncnt++;
	}
}

void dfs(int x) {
	if(vis[x]) return;
	vis[x] = true;
	for(int k = ind[x]; k != -1; k = nt[k]) {
		dfs(to[k]);
		mask[x][to[k]] = 1;
	}

	for(int k = ind[x]; k != -1; k = nt[k]) {
		mask[x] |= mask[to[k]];
	}
}

void dfs1(int x) {
	if(vis[x]) return;
	vis[x] = true;
	for(int k = ind[x]; k != -1; k = nt[k]) {
		ans[to[k]] |= mask[x];
		dfs1(to[k]);
		ans[x][to[k]] = 1;
	}
	for(int k = ind[x]; k != -1; k = nt[k]) {
		ans[x] |= mask[to[k]];
		ans[x] |= ans[to[k]];
	}
	ans[x] |= mask[x];
	ans[x][x] = 1;
}

int main() {
	scanf("%d%d", &n, &m);
	memset(ind, -1, sizeof ind);
	for(int i = 0 ; i < m; i++)	 {
		int x, y;
		scanf("%d%d", &x, &y);
		x--; 
		y--;
		a[i] = x; 
		b[i] = y;
		add(x, y);
	}
	for(int i = 0; i < n; i++)
	if(dfn[i] == 0) tarjan(i);
	memset(ind, -1, sizeof ind);
	cnt = 0;
	for(int i = 0; i < m; i++) 
	if(color[a[i]] != color[b[i]]) {
		add(color[a[i]], color[b[i]]);
	}
	memset(vis, 0, sizeof vis);
	for(int i = 0; i < ncnt; i++)
		dfs(i);
	for(int i = 0; i < ncnt; i++) mask[i][i] = 1;
	memset(ind, -1, sizeof ind);
	cnt = 0;
	for(int i = 0; i < m; i++) 
	if(color[b[i]] != color[a[i]]) 
		add(color[b[i]], color[a[i]]);

	memset(vis, 0, sizeof vis);
	for(int i = 0; i < ncnt; i++)
		dfs1(i);

	for(int i = 0; i < ncnt; i++) ans[i][i] = 1;
		
	int tot = 0;
	for(int i = 0; i < ncnt; i++) {
		int cur = number[i];
		for(int j = 0; j < ncnt; j++) {
			if(ans[i][j])
				tot += cur * number[j];
		}
	}
	cout << tot << endl;
	return 0;
}
