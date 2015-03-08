#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const LL MOD = 1000000000LL + 7;

LL a[100][100];
LL f[100];
LL m;
LL ans;


LL mul(LL a, LL b)
{
	LL ans = 0;
	while(a)	
	{
		if(a & 1) ans = (ans + b) % MOD;
		a >>= 1; b <<= 1;
	}
	return ans;
}

LL exgcd(LL a, LL b, LL &x, LL &y)
{
	if(b == 0) { x = 1; y = 0; return a; }
	LL res = exgcd(b, a % b, x, y);
	LL t = x;
	x = y;
	y = t - a / b * y;
	return res;
}

LL C(LL n, LL k)
{
	LL ans = 1;
	for(LL i = n; i > n - k; i--) ans = (ans * i) % MOD;
	for(LL i = 1; i <= k; i++)
	{
		LL x, y;
		exgcd(i, MOD, x, y);
		while(x < 0) x += MOD;
		ans = (ans * x) % MOD;
	}
	return ans;
}

LL A(LL n, LL k)
{
	LL ans = 1LL;	
	for(LL i = n; i > n - k; i--) ans = mul(ans, i);
	return ans;
}

LL pow(LL x, LL k)
{
	LL ans = 1;
	while(k)
	{
		if(k & 1) ans = (ans * x) % MOD;
		x = (x * x) % MOD;
		k >>= 1;
	}
	return ans;
}

void cala()
{
	for(int i = 0; i <= 10; i++)
		for(int j = 0; j <= i; j++) 
			a[i][j] = ((pow(8, i - j) * pow(2, j)) % MOD * C(i, j)) % MOD;
}


char s[100];
void calf()
{
	sprintf(s, "%I64d", m);
	int N = strlen(s);
	for(int ii = 0; ii <= N; ii++)
	{	
		LL tot = 0;
		f[ii] = 0;
		for(int i = 0; i < N; i++)
		{
			int x = s[i] - '0';
			if(tot > ii) break;
			int nl = x;
			if(x > 7 && tot + 1 <= ii) { f[ii] += a[N - i - 1][ii - tot - 1]; f[ii] %= MOD; }
			if(x > 7) nl--;
			if(x > 4 && tot + 1 <= ii) { f[ii] += a[N - i - 1][ii - tot - 1]; f[ii] %= MOD; }
			if(x > 4) nl--;
			f[ii] += (nl * a[N - i - 1][ii - tot]);
			f[ii] %= MOD;
			if(x == 4 || x == 7) tot++;
		}
		if(tot == ii) f[ii]++;
		f[ii] %= MOD;
	}
}


LL pp[11];
LL P(LL x)
{
	return pp[x];	
}
LL num[11];
void dfs(LL x, LL tot, LL c) 
{
	if(x == 0)
	{
		if(tot == 0) return;
		if(c > f[0]) return;
		num[0] = c;			
		LL tmp = 1LL;
		for(int i = 0; i < 10; i++)
		if(num[i])
		{
			tmp = (mul(tmp,  C(f[i], num[i])) % MOD) % MOD;
		}
		ans = (ans + tmp) % MOD;
		return;
	}
	if(!tot) return;
	if(f[x] == 0) dfs(x - 1, tot, c);
	else if(c == 7) { num[x] = 1; dfs(x - 1, tot, c - 1); return; }

	for(int i = 0; i <= c; i++)
	if(f[x] >= i && x * i < tot)
	{
		num[x] = i;
		dfs(x - 1, tot - x * i, c - i);
		num[x] = 0;
	}
	num[x] = 0;
}

int main()
{
#ifdef _DEBUG_
	freopen("test.in", "r", stdin);
#endif
	scanf("%I64d", &m);
	cala();
	calf();
#ifdef _DEBUG_
	int ans0[10];
	memset(ans0, 0, sizeof ans0);
	for(int i = 0; i <= m; i++)
	{
		sprintf(s, "%d", i);
		int k = strlen(s);
		int c = 0;
		for(int j = 0; j < k; j++)
			if(s[j] == '4' || s[j] == '7') c++;
		ans0[c]++;
	}
	for(int i = 0; i < 10; i++ ) cout << ans0[i] << " ";
	cout << endl;
	for(int i = 0; i < 10; i++) cout << f[i] << " ";
	cout << endl;
	cout << endl;
#endif
	f[0]--;
	ans = 0;
	pp[1] = 1;
	for(int i = 2; i < 10; i++) pp[i] = pp[i - 1] * i;
	for(int i = 1; i < 10; i++)
	if(f[i])
	{
		memset(num, 0, sizeof num);
		dfs(i, i, 7);
	}
	ans = mul(ans, 720L);
	printf("%I64d\n", ans);
	return 0;
}
