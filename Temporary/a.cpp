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

struct obj
{
	int a, b, c;
}f[1000];

int n;

int cmp(const obj &a, const obj &b)
{
	if(b.a - b.b == a.a - a.b && a.b == b.b) return a.c < b.c;
	if(b.a - b.b == a.a - a.b) return a.b < b.b;
	return (a.a - a.b) > (b.a - b.b);
}
int main()
{
	while(~scanf("%d", &n))
	{
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d", &f[i].a, &f[i].b);
			f[i].c = i;
		}
		sort(f, f + n, cmp);
		for(int i = 0; i < n; i++)
			if(i == 0) printf("%d", f[i].c);
			else printf(" %d", f[i].c);
		putchar('\n');
	}
	return 0;
}
