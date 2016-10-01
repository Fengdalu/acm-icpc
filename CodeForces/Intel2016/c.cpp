#include <bits/stdc++.h>
#include <sstream>

typedef long long ll;
const int N = 1001000;
ll ans[N];
ll f[N];
int fa[N];
int v[N];
int a[N];
int p[N];
int find(int x) {
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);

}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	for(int i = 1; i <= n; i++) scanf("%d", p + i);
	std::reverse(p + 1, p + n + 1);
	std::fill(v + 1, v + n + 1, -1);
	for(int i = 1; i <= n; i++) fa[i] = i;
	ll mx = 0;
	for(int i = 1; i <= n; i++) {
		ans[i] = mx;
		int t = p[i];
		ll sum = a[t];
		v[t] = a[t];
		if(t + 1 <= n && v[find(t + 1)] != -1) {
			sum += f[find(t + 1)];
			fa[find(t)] = find(t + 1);
		}
		if(t - 1 > 0 && v[t - 1] != -1) {
			sum += f[find(t - 1)];
			fa[find(t)] = find(t - 1);
		}
		f[find(t)] = sum;
		if(sum > mx) mx = sum;
	}
	for(int i = n; i > 0; i--) printf("%I64d\n", ans[i]);
	return 0;
}
