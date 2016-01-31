#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long

const int Maxn = 2010;
const int Mod = 1e9 + 7;
struct bit {
	LL buf[Maxn];
	int lowbit(int x) { return x & (-x); }
	void init() {
		memset(buf, 0, sizeof buf);
	}
	void insert(int x, LL c) {
		while(x < Maxn) {
			buf[x] = (buf[x] + c) % Mod;
			x += lowbit(x);
		}
	}

	LL query(int x) {
		LL ans = 0;
		while(x > 0) {
			ans = (ans + buf[x]) % Mod;
			x -= lowbit(x);
		}
		return ans;
	}
}c;
int p[Maxn];
LL dp[Maxn][Maxn];
LL dp1[Maxn][Maxn];
LL C[Maxn][Maxn];
int n;

void init() {
	for(int i = 1; i <= Maxn - 1; i++) {
		C[i][0] = 1;
		for(int j = 1; j < i; j++) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % Mod;
		}
		C[i][i] = 1;
	}
}

LL qpow(LL x, int p) {
	LL ans = 1;	
	while(p) {
		if(p & 1) ans *= x;
		ans %= Mod;
		p >>= 1;
		x *= x; x %= Mod;
	}
	return ans;
}

int main() {
	init();
	scanf("%d", &n)	;
	for(int i = 1; i <= n; i++) scanf("%d", &p[i]);
	for(int i = 1; i <= n; i++)	dp[i][1] = 1;
	for(int j = 2; j <= n; j++) {
		c.init();
		for(int i = 1; i <= n; i++) { 
			dp[i][j] = c.query(p[i] - 1);
			c.insert(p[i], dp[i][j - 1]);
		}
	}
	for(int j = 1; j <= n; j++) {
		for(int i = 1; i < n; i++) dp[n][j] = (dp[n][j] + dp[i][j]) % Mod;
	}

	LL ans = 0;
	for(int i = 1; i <= n; i++)	 {
		if(i == 1) {
			ans += dp[n][1];
			ans %= Mod;
		}
		else {
			LL tmp = 0;
			LL J = 1;
			for(int j = 0; j < i; j++) {
				tmp = (tmp + J * C[i][j] % Mod * qpow(i - j, n) % Mod) % Mod;
				J *= -1;
			}
			ans = ans + tmp * dp[n][i] % Mod;
			ans = ((ans % Mod) + Mod) % Mod;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

