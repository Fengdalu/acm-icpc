#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

int x[300000], y[300000];
int hx[300000], hy[300000];
int cx, cy;
std::pair<int, int> q[300000];
int f[300000], g[300000];
int n;

int main() {
	std::cin >> n;
	for(int i = 0; i < n; i++) std::cin >> x[i] >> y[i];
	for(int i = 0; i < n; i++) q[i] = std::make_pair(x[i], y[i]);
	for(int i = 0; i < n; i++) { hx[i] = x[i]; hy[i] = y[i]; }

	std::sort(hx, hx + n);
	cx = std::unique(hx, hx + n) - hx;
	std::sort(hy, hy + n);
	cy = std::unique(hy, hy + n) - hy;

	long long ans = 0;
	for(int i = 0; i < n; i++) {
		int a = std::lower_bound(hx, hx + cx, x[i]) - hx;
		int b = std::lower_bound(hy, hy + cy, y[i]) - hy;
		f[a]++;
		g[b]++;
	}
	for(int i = 0; i < cx; i++) ans += (long long)f[i] * (f[i] - 1) / 2;
	for(int i = 0; i < cy; i++) ans += (long long)g[i] * (g[i] - 1) / 2;
	std::sort(q, q + n);	
	int tot = 1;
	for(int i = 1; i < n; i++) {
		if(q[i] == q[i - 1]) tot++;
		else {
			ans -= (long long)tot * (tot - 1) / 2;
			tot = 1;
		}
	}
	ans -= (long long)tot * (tot - 1) / 2;
	std::cout << ans << std::endl;
} 

