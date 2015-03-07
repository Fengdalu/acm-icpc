#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define AA first
#define BB second
typedef long long LL;
typedef pair<int, int> PII;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define PB(x) push_back(x)
#define SZ size()
#define MP(a, b) make_pair(a, b)
#define OP begin()
#define ED end()
#define CLR clear()
#define INS(x) insert(x)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define MEM(a) memset(a, 0, sizeof a)
#define N 200000

int n, m;
int c[N];
vector<int>s;
LL ans;
LL h[N];

int exgcd(int a, int b, int &x, int &y)
{
	if(b == 0) { x = 1; y = 0; return a; }
	else
	{
		int res = exgcd(b, a % b, x, y);
		int x0 = x;
		x = y;
		y = x0 - a / b * y;
		return res;
	}
}

void cal1(int x)
{
	for(int i = 2; i * i <= x; i++)
	if(x % i == 0)
	{
		int p = lower_bound(s.begin(), s.end(), i) - s.begin();
		if(p != s.size() && s[p] == i)
		{
			while(x % i == 0)  { c[p]++; x /= i; }
		}
		else 
		{
			while(x % i == 0) { ans = (ans * i) % m; x /= i; }
		}
	}
	if(x != 1)
	{
		int p = lower_bound(s.begin(), s.end(), x) - s.begin();
		if(p != s.size() && s[p] == x)
			c[p]++;
		else ans = (ans * x) % m;
	}
}

int pow(int x, int c)
{
	int ans = 1;
	while(c)
	{
		if(c & 1) ans = (ans * x) % m;
		x = (x * x) % m;
		c >>= 1;
	}
	return ans;
}

void cal2(int x)
{
	for(int i = 2; i * i <= x; i++)
	if(x % i == 0)
	{
		int p = lower_bound(s.begin(), s.end(), i) - s.begin();
		if(p != s.size() && s[p] == i)
			while(x % i == 0)  { c[p]--; x /= i; }
		else 
		{
			int xx, y;
			exgcd(i, m, xx, y);
			while(xx < 0) xx += m;
			while(x % i == 0) { ans = (ans * xx) % m; x /= i;}
		}
	}
	if(x != 1)
	{
		int p = lower_bound(s.begin(), s.end(), x) - s.begin();
		if(p != s.size() && s[p] == x)
			c[p]--;	
		else
		{
			int xx, y;
			exgcd(x, m, xx, y);
			while(xx < 0) xx += m;
			ans = (ans * xx) % m;
		}
	}
}


int main()
{	
	while(~scanf("%d%d", &n, &m))
	{
		if(n == 0 && m == 0) break;
		MEM(c); s.CLR;
		int t = m;
		ans = 1LL;
		for(int i = 2; i * i <= m; i++)
		if(m % i == 0)
		{
			s.PB(i);
			while(m % i == 0) m /= i;
		}
		if(m != 1) s.PB(m); m = t;
		h[1] = 1;
		ans = 1;
		for(int i = 2; i <= n; i++)		
		{
			cal1(4 * i - 2);
			cal2(i + 1);
			h[i] = ans;
			for(int j = 0; j < s.SZ; j++)
			{	
				h[i] = (h[i] * pow(s[j], c[j])) % m;
			}
		}
		LL res = 0;
		for(int i = 1; i <= n; i++) res = (res + h[i]) % m;
		printf("%I64d\n", res);
	}
	return 0;
}

