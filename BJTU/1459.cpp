#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int c[100010];

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 0; i < n; i++) scanf("%d", &c[i]);
        int l = lower_bound(c, c + n, m) - c, r = upper_bound(c, c + n, m) - c;
        if(r == l) puts("-1");
        else
        {
            for(int i = l; i < r; i++) if(i == l) printf("%d", i + 1); else printf(" %d", i + 1);
            puts("");
        }
    }
    return 0;
}
