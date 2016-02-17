#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char s[10][10];
bool vis[10];
int n, k;
int ans;

void dfs(int l, int k) {
	if(l == n && k == 0) { ans++; return; }
	if(l == n) return;
	dfs(l + 1, k);
	if(k) {
		for(int i = 0; i < n; i++)
		if(!vis[i] && s[l][i] == '#') {
			vis[i] = true;
			dfs(l + 1, k - 1);
			vis[i] = false;
		}
	}
}

int run() {
	ans = 0;
	memset(vis, 0, sizeof vis);
	if(2 != scanf("%d%d", &n, &k)) return 1;
	if(n == -1 && k == -1) return 1;
	for(int i = 0; i < n; i++) scanf("%s", s[i]);
	dfs(0, k);
	printf("%d\n", ans);
	return 0;
}

int main() {
	while(!run());
	return 0;
}
