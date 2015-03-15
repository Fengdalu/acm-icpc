#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
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
const int N = 100010;

int a[N], b[N];
int c[N]; 
int num[N];
int f[500][N];
int l[N], r[N];
int ans[N];
int cnt;
int n, m; 
int nn;

int main()
{
	ios::sync_with_stdio(false);
	int n, k;	
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> l[i] >> r[i];
	int mn = 0;
	for(int i = 0; i < m; i++) cmax(mn, r[i] - l[i] + 1);
	memcpy(b, a, sizeof a);
	for(int i = n; i >= 1; i--) a[i] = a[i - 1];
	sort(b, b + n);
	nn = unique(b, b + n) - b;
	memset(c, 0, sizeof c);
	for(int i = 1; i <= n; i++)
	{
		int pos = lower_bound(b, b + nn, a[i]) - b;
		c[pos]++;
	}
	int cnt = 0;
	for(int i = 0; i < nn; i++)
	if(c[i] >= b[i] && mn >= b[i])
		num[cnt++] = b[i];
	memset(f, 0, sizeof f);
	for(int i = 0; i < cnt; i++)
	{
		f[i][0] = 0;
		for(int j = 1; j <= n; j++)
			f[i][j] = f[i][j - 1] + (a[j] == num[i]);
	}
	for(int i = 0; i < cnt; i++)	
	{
		for(int j = 0; j < m; j++)
		{
			if(f[i][r[j]] - f[i][l[j] - 1] == num[i]) ans[j]++;
		}
	}
	for(int i = 0; i < m; i++) cout << ans[i] << endl;
	return 0;
}
