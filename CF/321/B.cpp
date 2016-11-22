#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define FOR(i, n) for(int i = 0; i < n; i++)
#define AA first
#define BB second
#define PB(x) push_back(x)
#define SZ size()
#define MP(a, b) make_pair(a, b)
#define OP begin()
#define ED end()
#define CLR clear()
#define LL long long
typedef pair<int, int> PII;
#define N 100100

int n, d;
PII f[N];

int main()
{
    scanf("%d%d", &n, &d);
    for(int i = 0; i < n; i++) scanf("%d%d", &f[i].AA, &f[i].BB);
    sort(f, f + n);
    int j = 0;
    LL sum = f[0].BB;
    LL ans = 0;
    for(int i = 0; i < n; i++)
    {
        while(j + 1 < n && f[j + 1].AA - f[i].AA < d) { j++; sum += f[j].BB; }
        ans = max(ans, sum);
        sum -= f[i].BB;
    }
    printf("%I64d\n", ans);
	return 0;
}
