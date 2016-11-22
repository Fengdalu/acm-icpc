#include <iostream>
#include <cstdio>
#include <algorithm>

int f[200000];
char s[200020];
int n, k;

bool check(int l) {
	for(int i = 1; i <= n; i++) 
	if(s[i] == '0') {
		int b = std::min(n, i + l);
		int a = std::max(1, i - l);
		if(f[b] - f[a - 1] > k) return true;
	}
	return false;
}
int main() {
	scanf("%d%d", &n, &k);
	scanf("%s", s + 1);
	f[0] = 0;
	for(int i = 1; i < n + 1; i++)
		f[i] = f[i - 1] + 1 - (s[i] - '0');
	int l = 1, r = n - 1;
	while(l < r) {
		int mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l);
}
