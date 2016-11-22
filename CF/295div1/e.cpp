#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long
#define AA first
#define BB second
#define SZ size()
#define N 200000

const LL MOD = 1e9 + 7;
LL n, k;
char s[N];
LL a[N];
LL c[N];


void init()
{
	c[0] = 1;
	c[1] = 1;
	for(int i = 2; i <= 100000; i++)
		c[i] = (c[i - 1] * i) % MOD;
}

LL exgcd(LL a, LL b, LL &x, LL &y)
{
	if(!b) { x = 1; y = 0; return a; }
	LL r = exgcd(b, a % b, x, y);
	LL x0 = x;
	x = y;
	y = x0 - a / b * y;
	return r;
}

LL inv(LL a) 
{
	LL x, y;
	exgcd(a, MOD, x, y);
	while(x < 0) x += MOD;
	return x;
}

LL C(LL n, LL k)
{
	if(k > n) return 0;
	return c[n] * inv(c[n - k]) % MOD * inv(c[k]) % MOD;
}

LL pow(LL x, LL k)
{
	LL ans = 1;
	while(k)
	{
		if(k & 1) ans = (ans * x) % MOD;
		k >>= 1; x = (x * x) % MOD;
	}
	return ans;
}

int main()
{		
	init();
	ios::sync_with_stdio(false);
	cin >> n >> k;
	cin >> s;
	memset(a, 0, sizeof a);
	a[0] = s[0] - '0';
	for(int i = 1; i < n; i++)
		a[i] = a[i - 1] + s[i] - '0';	
	LL ans = 0;
	for(LL j = 0; j <= n - 2; j++)				
	{
		ans = (ans + pow(10, j) * C(n - 1 - j - 1, k - 1) % MOD * a[n - j - 2] % MOD) % MOD;
	}
	for(int i = 0; i < n; i++) 
	{	
		ans = (ans + C(i, k) * (s[i] - '0') % MOD * pow(10, n - i - 1) % MOD) % MOD;
	}
	cout << ans << endl;	
	return 0;
}
