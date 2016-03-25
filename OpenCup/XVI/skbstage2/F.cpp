#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>

const int maxn = 310;
const int inf = 1e7;
int n;
int c[maxn][maxn];
int f[maxn];
int vis[maxn];
int pre[maxn];
std::vector<int>g[maxn];

void dfs(int x, int v) {
	vis[x] = v;
	for(int i = 0; i < g[x].size(); i++)
	if(vis[g[x][i]] == 0)
		dfs(g[x][i], v);
}

int get(int x) {
	for(int i = 0; i < n; i++) f[i] = inf;
	f[x] = 0;
	std::set<std::pair<int, int> >q;
	for(int i = 0; i < n; i++) q.insert(std::make_pair(f[i], i));
	while(q.size()) {
		int p = q.begin()->second;
		q.erase(q.begin());
		for(int i = 0; i < n; i++)
		if(i != p && c[p][i] != -1 && f[p] + c[p][i] < f[i]) {
			q.erase(q.find(std::make_pair(f[i], i)));
			f[i] = f[p] + c[p][i];
			pre[i] = p;
			q.insert(std::make_pair(f[i], i));
		}
	}
	for(int i = 0; i < n; i++) g[i].clear();
	for(int i = 0; i < n; i++) 
		if(i != x) g[pre[i]].push_back(i);
	memset(vis, 0, sizeof vis);
	for(int i = 0; i < g[x].size(); i++)
		dfs(g[x][i], i + 1);
	int ans = inf;
	for(int i = 0; i < n; i++)				
		for(int j = 0; j < n; j++)
		if(i != x && j != x && i != j)
			if(f[i] != inf && f[j] != inf && 
			c[i][j] != -1 && vis[i] != vis[j]) {
				ans = std::min(ans, f[i] + f[j] + c[i][j]);	
			}
	for(int i = 0; i < n; i++)
	if(i != x && c[x][i] != -1 && pre[i] != x)
		ans = std::min(ans, f[i] + c[x][i]);
	if(ans == inf) return -1;
	return ans;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &c[i][j]);
	for(int i = 0; i < n; i++) 
		printf("%d\n", get(i));
	return 0;
}
