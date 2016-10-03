#include <bits/stdc++.h>

const int N = 10000;
int f[N];
int a[N];
int oth;
int n, m;
typedef long long ll;

int check(int w) {
	ll tot = 0;
	for(int i = 1; i <= m; i++) {
		if(f[i] < w)
			tot += std::max(0, w - f[i]);
		else tot -= f[i] - w;
	}
	return tot <= oth;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) scanf("%d", a + i);
	oth = 0;
	for(int i = 0; i < n; i++) if(a[i] <= m) f[a[i]]++; else oth++;
	int l = 0, r = n;
	while(l < r) {
		int mid = (l + r + 1) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	int up = l;
	int modify = 0;
	int J = 1;
	for(int i = 0; i < n; i++) {
		if(a[i] > m) {
			while(f[J] >= up && J <= m) J++;
			if(J == m + 1) break;
			modify++;
			f[J]++;
			a[i] = J;
		}
	}
	while(J <= m) {
		int i = 0;
		while(J != m + 1 && f[J] >= up) J++;
		if(J == m + 1) break;
		while(i != n && f[a[i]] <= up) i++;
		f[a[i]]--;
		f[J]++;
		a[i] = J;
		i++;
		modify++;
	}
	printf("%d %d\n", up, modify);
	for(int i = 0; i < n; i++) printf("%d ", a[i]);
	return 0;
}

