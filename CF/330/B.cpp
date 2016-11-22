#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;
const LL Mod = 1e9 + 7;

LL qpow(LL x, LL p) {
	LL ans = 1;
	while(p) {
		if(p & 1) ans *= x;
		ans %= Mod;
		p >>= 1; x *= x;
		x %= Mod;
	}
	return ans;
}

LL n, k;
LL a[200000], b[200000];
LL t[200000];

void init() {
	t[0] = 1;
	for(int i = 1; i <= 11; i++) t[i] = (t[i - 1] * 10LL);
}

void exgcd(LL a, LL b, LL &x, LL &y) {
	if(b == 0)  { x = 1; y = 0; return;  }
	exgcd(b, a % b, x, y);
	LL t = y;
	y = x - a / b * y;
	x = t;
}

LL inv(LL x) {
	LL b, c; 
	exgcd(x, Mod, b, c);
	b = b % Mod + Mod;
	return b % Mod;
}

void run() {
	init();
	cin >> n >> k;
	for(int i = 0; i < n / k; i++) cin >> a[i];
	for(int i = 0; i < n / k; i++) cin >> b[i];
	LL ans = 1;
	for(int i = 0; i < n / k; i++) {
		LL tot = 0;
		LL g = 0;
		tot += (t[k] - 1) / a[i] + 1;
		g = (t[k - 1] * (b[i] + 1) - 1) / a[i];
		if(b[i]) g -= (t[k - 1] * (b[i]) - 1) / a[i];
		if(!b[i]) g++;
		tot -= g;
		ans *= tot;
		ans %= Mod;
	}
	cout << ans << endl;
}

int main() {
	run();
}
