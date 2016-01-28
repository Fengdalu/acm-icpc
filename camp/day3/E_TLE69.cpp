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

#define N 30010
#define M 100000000 
int fa[N], top[N], w[N], son[N], dep[N], sz[N], r[N];
int city[N];
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

void dfs1(int x, int d) {
	dep[x] = d;
	son[x] = 0;
	sz[x] = 1;
	for(int k = ind[x]; k != -1; k = nt[k]) if(t[k] != fa[x]){
		fa[t[k]] = x;
		dfs1(t[k], d + 1);
		sz[x] += sz[t[k]];
		if(sz[t[k]] > sz[son[t[k]]]) son[x] = t[k];
	}
}

void dfs2(int x, int tt) {
	w[x] = ++cnt2;
	city[w[x]] = x;
	top[x] = tt;
	if(son[x]) dfs2(son[x], tt);
	for(int k = ind[x]; k != -1; k = nt[k]) if(t[k] != fa[x] && t[k] != son[x])
	{
		dfs2(t[k], t[k]);
	}
}

int op1(int id, int x, int y) { 
	for(int i = x; i <= y; i++) add(city[i], id + n);
}

int query1(int id, int x, int y) {
	int fx = top[x], fy = top[y];
	while(fx != fy) {
		if(dep[fx] < dep[fy]) {
			swap(x, y);
			swap(fx, fy);
		}
		op1(id, w[fx], w[x]);
		x = fa[top[x]];
		fx = top[x];
	}
	if(dep[x] > dep[y]) swap(x, y);
	op1(id, w[x], w[y]);
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
	dfs1(1, 1); dfs2(1, 1);
	cnt1 = 0;
	memset(ind, -1, sizeof ind);
	cnt1 = 0;
	for(int i = 0; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		query1(i + 1, x, y);
	}
	int res = hungary();
	if(res == n) {
		puts("Yes");
		for(int i = 1; i <= n; i++) printf("%d ", linker[i + n]);
	}
	else puts("No");
	return 0;
}
