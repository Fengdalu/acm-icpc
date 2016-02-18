#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const double eps = 1e-10;
int f[2000], g[2000];
double h[2000];
int n;

void run() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%lf", &h[i]);
	for(int i = 0; i < n; i++) {
		f[i] = 1;
		for(int j = 0; j < i; j++) 
		if(h[j] + eps < h[i]) {
			f[i] = max(f[i], f[j] + 1);
		}
	}
	for(int i = n - 1; i >= 0; i--) {
		g[i] = 1;
		for(int j = i + 1; j < n; j++) {
			if(h[j] + eps < h[i]) {
				g[i] = max(g[j] + 1, g[i]);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans = max(f[i], ans);
		ans = max(g[i], ans);
	}
	for(int i = 0; i < n; i++) 
		for(int j = i; j < n; j++) {
			if(i == j) ans = max(ans, f[i] + g[j] - 1);
			else ans = max(ans, f[i] + g[j]);
		}
	printf("%d\n", n - ans);
}

int main() {
	run();
	return 0;
}
