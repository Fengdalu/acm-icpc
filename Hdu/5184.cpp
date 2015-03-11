#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long
const LL MOD = 1e9 + 7;

LL a[2000000];
LL exgcd(LL a, LL b, LL &x, LL &y)
{
	if(b == 0) { x = 1; y = 0; return a; }
	LL res = exgcd(b, a % b, x, y);
	LL x0 = x;
	x = y;
	y = x0 - a / b * y;
	return res;
}

void init()
{
	a[1] = 1; a[0] = 1;
	for(LL i = 2; i <= 1000000; i++) a[i] = (a[i - 1] * i) % MOD;
}

LL Ni(LL x)
{
	LL a, b;
	exgcd(x, MOD, a, b);
	while(a < 0) a += MOD;
	return a;
}

LL C(LL n, LL k)
{
	return (a[n] * Ni(a[n - k])) % MOD * Ni(a[k]) % MOD;
}

char s[2000000];
LL n;

LL mul(LL a, LL b)
{
	LL ans = 0;
	while(a)
	{
		if(a & 1) ans = (ans + b) % MOD;
		a >>= 1; b <<= 1;
		if(b >= MOD) b -= MOD;
	}
	return ans;
}

int main()
{
#ifdef _DEBUG_
freopen("test.in", "r", stdin);
#endif
	init();
	ios::sync_with_stdio(false);
	while(cin >> n)
	{
		s[0] = 0;
		cin >> s;
		if(n & 1) { cout << 0 << endl;; continue; }
		n >>= 1;
		LL P = 0, Q = 0;
		int len = strlen(s);
		bool flg = false;
		for(int i = 0; i < len; i++) 
		{
			if(s[i] == '(') P++; else Q++;
			if(Q > P) {flg = true; break;}
		}
		if(flg) { cout << 0 << endl;; continue; }
		LL p = n - Q; LL q = n - P;
		LL ans = mul(max(0LL, p + 1LL - q), Ni(p + 1LL)) % MOD;
		ans = mul(ans, C(p + q, q)) % MOD;
		cout << ans << endl;
	}
	return 0;
}
