#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn = 500010;

int a[Maxn], c[Maxn];
int h[Maxn];
int n;
int lowbit(int x) { return x & (-x); }

void insert(int p) {
	while(p <= n) {
		c[p] += 1;
		p += lowbit(p);
	}
}

int cal(int p) {
	int ans = 0;
	while(p) {
		ans += c[p];
		p -= lowbit(p);
	}
	return ans;
}

int run() {
	scanf("%d", &n);
	if(n == 0) return 0;
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < n; i++) h[i] = a[i];
	memset(c, 0, sizeof c);
	sort(h, h + n);
	int cnt = unique(h, h + n) - h;
	for(int i = 0; i < n; i++) a[i] = lower_bound(h, h + cnt, a[i]) - h + 1;
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		ans += cal(n) - cal(a[i]);
		insert(a[i]);
	}
	printf("%lld\n", ans);
	return 1;
}

int main() {
	while(run());
	return 0;
}






