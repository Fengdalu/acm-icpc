#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
LL mod;

LL gcd(LL a, LL b) {

	if(b == 0) return a;
	return gcd(b, a % b);
}

void exgcd(LL a, LL b, LL &x, LL &y) {
	if(b == 0) {
		x = 1;
		y = 0;
	}
	else {
		exgcd(b, a % b, x, y);
		LL y1 = y;
		y = x - a / b * y;
		x = y1;
	}
}

LL inv(LL a) {
	LL x, y;
	exgcd(a, mod, x, y);
	x = (x % mod + mod) % mod;
	return x;
}

int main() {
	LL a, b, c, k;		
	while(~scanf("%lld%lld%lld%lld", &a, &b, &c, &k)) {
		if(!a && !b && !c && !k) break;
		//if(a == b) { printf("0\n"); continue; }
		mod = 1LL << k;
		LL r = (b - a + mod) % mod;
		LL p = gcd(c, mod);
		if(r % p != 0) {
			puts("FOREVER");
		}
		else {
			c /= p;
			mod /= p;
			r /= p;
			printf("%lld\n", r * inv(c) % mod);
		}
	}
	return 0;
}
