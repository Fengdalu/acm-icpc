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
typedef pair<LL, LL> PUU;
typedef pair<int, int> PII;
#define N 10001

int n, k;
PUU a[N];
char buf[N];
multiset<LL>s;
multiset<LL>::iterator A, B;

LL ABS(LL x)
{
    if(x < 0) return -x;
    return x;
}

int main()
{
    int T; scanf("%d", &T);
    FOR(_I, T)
    {
        scanf("%d%d", &n, &k);
        s.clear();
        FOR(i, n)
        {
            scanf("%s", buf);
            a[i].AA = a[i].BB = 0;
            for(int j = 0; j < k; j++) a[i].AA = a[i].AA * 2LL + (buf[j] - '0');
            for(int j = 0; j < k; j++) a[i].BB = a[i].BB * 2LL + !(buf[j] - '0');
            s.insert(a[i].AA); s.insert(a[i].BB);
        }
        LL ans = 0;
        FOR(i, n)
        {
            s.erase(s.find(a[i].AA)); s.erase(s.find(a[i].BB));
            if(s.SZ)
            {
                A = s.OP; B = s.ED; B--;
                ans = max(ans, ABS(*A - a[i].AA));
                ans = max(ans, ABS(*B - a[i].AA));
                ans = max(ans, ABS(*A - a[i].BB));
                ans = max(ans, ABS(*B - a[i].BB));
            }
            s.insert(a[i].BB); s.insert(a[i].AA);
        }
        printf("Case #%d: %lld\n", _I + 1, ans);
    }
	return 0;
}
