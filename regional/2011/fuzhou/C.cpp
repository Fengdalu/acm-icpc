#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const int Maxn = 50010;
const int Maxm = Maxn * 2;
const int Pow = 20;
int ind[Maxn];
int t[Maxm], nt[Maxm], c[Maxm];
int f1[Maxn][Pow], f2[Maxn][Pow];
int dp1[Maxn][2], to1[Maxn][2];
int mm[Maxn];
int dp2[Maxn];
int cnt;
int n;
int root;

void add(int a, int b, int v) {
	t[cnt] = b;
	c[cnt] = v;
	nt[cnt] = ind[a];
	ind[a] = cnt++;
}

void dfs1(int x, int fa) {
	for(int k = ind[x]; k != -1; k = nt[k])
	if(t[k] != fa) dfs1(t[k], x);

	memset(to1[x], 0, sizeof to1[x]);
	memset(dp1[x], 0, sizeof dp1[x]);

	for(int k = ind[x]; k != -1; k = nt[k]) 
	if(t[k] != fa) {
		if(dp1[t[k]][0] + c[k] > dp1[x][1]) {
			dp1[x][1] = c[k] + dp1[t[k]][0];
			to1[x][1] = t[k];
			if(dp1[x][0] < dp1[x][1]) {
				std::swap(dp1[x][0], dp1[x][1]);
				std::swap(to1[x][0], to1[x][1]);
			}
		}
	}
}

void dfs2(int x, int fa) {
	if(fa != -1) {
		int v = dp2[x];
		dp2[x] = std::max(dp2[x], dp2[fa] + v);
		if(to1[fa][0] != x) dp2[x] = std::max(dp2[x], dp1[fa][0] + v);
		else if(to1[fa][1] != 0) dp2[x] = std::max(dp2[x], dp1[fa][1] + v);
	}
	for(int k = ind[x]; k != -1; k = nt[k]) 
	if(t[k] != fa) {
		dp2[t[k]] = c[k];
		dfs2(t[k], x);
	}
}


void rmq() {
	for(int i = 1; i <= n; i++) f1[i][0] = f2[i][0] = std::max(dp1[i][0], dp2[i]);

	for(int j = 0; j < Pow; j++)
		for(int i = 1; i < n + 1; i++)
	    if(i + (1 << (j + 1)) <= n + 1) {
			f1[i][j + 1] = std::max(f1[i][j], f1[i + (1 << j)][j]);
		}

	for(int j = 0; j < Pow; j++)
		for(int i = 1; i < n + 1; i++)
	    if(i + (1 << (j + 1)) <= n + 1) {
			f2[i][j + 1] = std::min(f2[i][j], f2[i + (1 << j)][j]);
		}
}

int cal1(int l, int r) {
	int k = mm[r - l + 1];
	return std::max(f1[l][k], f1[r - (1 << k) + 1][k]);
}

int cal2(int l, int r) {
	int k = mm[r - l + 1];
	return std::min(f2[l][k], f2[r - (1 << k) + 1][k]);
}

int main() {
	int m;
	mm[0] = -1;
	for(int i = 1; i < Maxn; i++) {
		if((i & (i - 1)) == 0) mm[i] = mm[i - 1] + 1;
		else mm[i] = mm[i - 1];
	}

	while(~scanf("%d%d", &n, &m)) {
		if(!n && !m) break;
		for(int i = 1; i <= n; i++) ind[i] = -1;
		cnt = 0;
		for(int i = 0; i < n - 1; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			add(a, b, c);
			add(b, a, c);
		}
		dfs1(1, -1);
		dfs2(1, -1);
		rmq();
		while(m--) {
			int q;
			scanf("%d", &q);
			int r = 1;
			int ans = 0;
			for(int i = 1; i <= n; i++) {
				while(r <= i && cal1(r, i) - cal2(r, i) > q) r++;
				ans = std::max(ans, i - r + 1);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}