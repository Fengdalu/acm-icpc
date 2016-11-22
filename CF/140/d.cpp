#include <set>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
#define BG begin()
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define N 200000
#define LL long long

LL a[N];
LL f[N];
int n, k, m;
LL ans[N];

int cmp(const int &a, const int &b) { return a > b; }
LL pow(LL x, LL k)
{
	LL ans = 1;
	while(k)
	{	
		if(k & 1) ans *= x;
		x *= x; k >>= 1;
	}
	return ans;
}

int main()
{	
#ifdef _FILE_
	freopen("test.in", "r", stdin);
#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
	sort(a + 1, a + n + 1);
	LL k0 = 0;
	for(int i = 1; i <= n; i++)
		k0 += a[i] * (n - i);
	memset(ans, 0, sizeof ans);
	ans[1] = k0;
	sort(a + 1, a + n + 1, cmp);
	f[1] = a[1];
	for(int i = 2; i <= n; i++) f[i] = f[i - 1] + a[i];

	scanf("%d", &m);
	for(int i = 0; i < m; i++)
	{
		LL k; scanf("%I64d", &k);
		if(ans[k] != 0 || k == 1) { printf("%I64d ", ans[k]); continue; }
		LL tmp = 0;
		LL cnt = 2;
		while(true)
		{
			LL l = (pow(k, cnt - 1) - 1) / (k - 1);
			LL r = (pow(k, cnt) - 1) / (k - 1);
			tmp += (f[min(r, (LL)n)] - f[l]) * (cnt - 1);
			if(r >= (LL)n) break;
			cnt++;
		}
		ans[k] = tmp;
		printf("%I64d ", tmp);
	}
	putchar('\n');
	return 0;
}
