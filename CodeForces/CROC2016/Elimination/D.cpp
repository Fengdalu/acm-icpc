#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

const int maxn = 100010;
const int maxm = 100010;
int x[maxm], y[maxm];
int ind[maxn];
int to[maxm], nt[maxm];
int in[maxm];
bool vis[maxn];
int cnt;
int n, m;

void add(int a, int b) {
	in[b]++;
	to[cnt] = b;
	nt[cnt] = ind[a];
	ind[a] = cnt++;
}

bool check(int m) {
	memset(ind, -1, sizeof ind);
	memset(in, 0, sizeof in);
	memset(vis, 0, sizeof vis);
	cnt = 0;
	for(int i = 0; i < m; i++) add(x[i], y[i]);
	std::queue<int>q;
	int cc = 0;
	for(int i = 1; i <= n; i++) 
	if(in[i] == 0) {
		cc++;
		q.push(i);
	}
	if(cc > 1) return false;
	while(q.size()) {
		int x = q.front();
		vis[x] = true;
		cc = 0;
		q.pop();
		for(int k = ind[x]; k != -1; k = nt[k])	{
			in[to[k]]--;
			if(!vis[to[k]] && in[to[k]] == 0) {
				cc++;
				q.push(to[k]);
			}
		}
		if(cc > 1) return false;
	}
	for(int i = 1; i <= n; i++) if(!vis[i]) return false;
	return true;
}

int main() {
	scanf("%d%d", &n, &m);
	memset(ind, -1, sizeof ind);
	cnt = 0;
	for(int i = 0; i < m; i++) {
		scanf("%d%d", &x[i], &y[i]);
		add(x[i], y[i]);
	}
	std::queue<int>q;
	for(int i = 1; i <= n; i++) if(in[i] == 0) q.push(i);
	memset(vis, 0, sizeof vis);
	while(q.size()) {
		int x = q.front();
		vis[x] = true;
		q.pop();
		for(int k = ind[x]; k != -1; k = nt[k]) {
			in[to[k]]--;
			if(in[to[k]] == 0) q.push(to[k]);
		}
	}
	bool flag = false;
	for(int i = 1; i <= n; i++) if(!vis[i]) flag = true;
	if(flag == true) {
		puts("-1");
	}
	else {
		int l = 1, r = m;	
		while(l < r) {
			int mid = (l + r) / 2;
			if(check(mid)) r = mid;
			else l = mid + 1;
		}
		if(!check(l))puts("-1");
		else printf("%d\n", l);
	}
	return 0;
}
