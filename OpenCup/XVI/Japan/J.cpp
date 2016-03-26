#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

const int maxn = 400010;
const int maxm = 1200010;
int ind[maxn];
int to[maxm], nt[maxm];
int c[maxn];
int ans[maxn];
int in[maxn];
int fa[maxn];
int n, m;
int cnt;
std::vector<std::pair<int, int> > v[maxn];

void add(int a, int b) {
	to[cnt] = b;
	in[b]++;
	nt[cnt] = ind[a];
	ind[a] = cnt++;
}

int find(int x) {
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

int main() {
	scanf("%d", &n);
	memset(ind, -1, sizeof ind);
	memset(in, 0, sizeof in);
	cnt = 0;
	for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
	for(int i = 1; i <= n; i++) fa[i] = i;
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if(c[x] <= c[y]) v[x].push_back(std::make_pair(c[y], y));
		else v[y].push_back(std::make_pair(c[x], x));
	}
	for(int i = 1; i <= n; i++)	
	if(v[i].size()) {
		std::sort(v[i].begin(), v[i].end());
		if(c[i] == v[i][0].first) fa[find(i)] = find(v[i][0].second);

		for(int j = 0; j < v[i].size() - 1; j++) 
			if(v[i][j].first == v[i][j + 1].first)
				fa[find(v[i][j].second)] = find(v[i][j + 1].second);
	}
	for(int i = 1; i <= n; i++)	
	if(v[i].size()) {
		if(c[i] != v[i][0].first)
			add(find(i), find(v[i][0].second));
		for(int j = 0; j < v[i].size() - 1; j++) {
			if(v[i][j].first != v[i][j + 1].first)
				add(find(v[i][j].second), find(v[i][j + 1].second));
		}
	}
	std::queue<int>q;
	for(int i = 1; i <= n; i++) 
	if(fa[i] == i && in[i] == 0) q.push(i);
	memset(ans, 0, sizeof ans);
	while(q.size()) {
		int x = q.front();
		q.pop();
		for(int k = ind[x]; k != -1; k = nt[k]) {
			ans[to[k]] = std::max(ans[to[k]], ans[x] + 1);
			in[to[k]]--;
			if(in[to[k]] == 0) q.push(to[k]);
		}
	}
	long long tot = 0;
	for(int i = 1; i <= n; i++)
		tot += ans[find(i)];
	std::cout << n + tot << std::endl;
	return 0;
}
