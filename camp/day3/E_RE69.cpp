#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define MID(x, y) (x + y) / 2
#define PII pair<int, int>
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
#define PB(x) push_back(x)
#define OP begin()
#define ED end()

#define N 20010
#define M 100000000 
int d[N];
int linker[N];
bool used[N];
int t[M], nt[M];
int ind[N];
int cnt1, cnt2, cnt3;
int n, m;

void add(int a, int b) {
	t[cnt1] = b;
	nt[cnt1] = ind[a];
	ind[a] = cnt1++;
}

int dfs(int u) {
	for(int k = ind[u]; k != -1; k = nt[k]) {
		int v = t[k];
		if(!used[v]) {
			used[v] = true;
			if(linker[v] == -1 || dfs(linker[v])) {
				linker[v] = u;
				return true;
			}
		}
	}
	return false;
}

int hungary() {
	int res = 0;
	//memset(linker, -1, sizeof linker);
	for(int i = n; i <= n + n; i++) linker[i] = -1;
	for(int i = 1; i <= n; i++) {
		//memset(used, 0, sizeof used);
		for(int i = 1; i <= n + n; i++) used[i] = false;
		if(dfs(i)) res++;
	}
	return res;
}

const int POW = 20;
int p[N][POW + 1];
void dfs(int u, int fa) {
	d[u] = d[fa] + 1;
	p[u][0] = fa;
	for(int i = 1; i < POW; i++) p[u][i] = p[p[u][i - 1]][i - 1];
	for(int k = ind[u]; k != -1; k = nt[k]) if(t[k] != fa) {
		dfs(t[k], u);
	}
}

int lca(int a, int b) {
	if(d[a] > d[b]) swap(a, b);
	if(d[a] < d[b]) {
		int del = d[b] - d[a];
		for(int i = 0; i < POW; i++) if(del & (1 << i)) b = p[b][i];
	}
	if(a != b) {
		for(int i = POW - 1; i >= 0; i--) 
			if(p[a][i] != p[b][i]) a = p[a][i], b = p[b][i];
		a = p[a][0], b = p[b][0];
	}
	return a;
}


int a[M], b[M];
void adde(int x, int y) {
	a[cnt2] = x; 
	b[cnt2] = y;
	cnt2++;
}

void dfs(int x, int id, int T) {
	adde(x, id + n);
	if(x == T) return;
	for(int k = ind[x]; k != -1; k = nt[k]) if(d[t[k]] == d[x] - 1) dfs(t[k], id, T);
}

int main() {
	scanf("%d", &n);
	memset(ind, -1, sizeof ind);
	cnt1 = cnt2 = cnt3 = 0;
	for(int i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y); add(y, x);
	}
	dfs(1, 1);
	cnt2 = 0;
	for(int i = 0; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		int r = lca(x, y);
		dfs(x, i + 1, r);
		dfs(y, i + 1, r);
	}
	memset(ind, -1, sizeof ind);
	for(int i = 0; i <= cnt2; i++) add(a[i], b[i]);
	int res = hungary();
	if(res == n) {
		puts("Yes");
		for(int i = 1; i <= n; i++) printf("%d ", linker[i + n]);
	}
	else puts("No");
	return 0;
}
