#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int Maxn = 500010;
long long l[Maxn], r[Maxn];
long long c[Maxn];
long long a, b, n, t;
char s[Maxn];

int main() {
	std::cin >> n >> a >> b >> t;
	std::cin >> s;
	for(int i = 0; i < n; i++) 
	if(s[i] == 'w') c[i] = 1 + b;
	else c[i] = 1;

	l[0] = 0;
	r[0] = 0;
	for(int i = 1; i < n; i++) {
		l[i] = a + l[i - 1] + c[i];
		r[i] = a + r[i - 1] + c[n - i];
	}
	if(t < c[0]) {
		std::cout << 0 << std::endl;
		return 0;
	}
	else t -= c[0];
	long long ans = 1;
	for(int i = 1; i < n; i++) 
	if(t >= l[i]) {
		long long tot = t - l[i];
		if(tot >= i * a) {
			long long v = tot - (i * a);
			long long p = std::upper_bound(r, r + n, v) - r - 1;
			ans = std::max(ans, i + p + 1);
		}
		else ans = std::max(ans, (long long)i + 1);
	}
	for(int i = 1; i < n; i++) 
	if(t >= r[i]) {
		long long tot = t - r[i];
		if(tot >= i * a) {
			long long v = tot - (i * a);
			long long p = std::upper_bound(l, l + n, v) - l - 1;
			ans = std::max(ans, i + 1 + p);
		}
		else ans = std::max(ans, (long long)i + 1);
	}
	ans = std::min(ans, n);
	std::cout << ans << std::endl;
}
