#include <iostream>
#include <cstdio>
#include <cstring>

const int maxn = 300010;
int p[maxn];
int pre[maxn];
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		p[x] = i;
	}
	for(int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a = p[a];
		b = p[b];
		if(a > b) std::swap(a, b);
		pre[b] = std::max(a, pre[b]);		
	}
	int cur = 0;
	long long ans = 0;
	for(int i = 1; i <= n; i++) {
		cur = std::max(cur, pre[i]);
		ans += (long long)(i - cur);
	}
	std::cout << ans << std::endl;
	return 0;
}
