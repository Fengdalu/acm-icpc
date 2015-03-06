#include <set>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define BG begin()
#define N 200000
#define LL long long
#define _FILE_

LL a[N];
int n, k, m;
LL ans = 9223372036854775807LL;

int cmp(const int &a, const int &b) { return a < b; }

int main()
{	
#ifdef _FILE_
	freopen("test.in", "r", stdin);
#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
	sort(a + 1, a + n + 1, cmp);
	LL k0 = 0;
	for(int i = 1; i <= n; i++)
		k0 += a[i] * (n - i);
	cout << k0 << endl;

	scanf("%d", &m);
	for(int i = 0; i < m; i++)
	{
		int k; scanf("%d", &k);
		LL tmp = 0;
					
	}
	return 0;
}
