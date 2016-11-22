#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long
int a[10];

int main()
{
    for(int i = 0; i < 6; i++) scanf("%d", &a[i]);
    LL ans = 0;
    int x = 3 + (a[1] - 1) * 2;
    for(; a[0] && a[2];)
    {
        ans += x;
        a[0]--; a[2]--; if(a[0] && a[2])x += 2;
    }
    int y = 3 + 2 * (a[4] - 1);
    for(; a[3] && a[5];)
    {
        ans += (LL)y;
        a[3]--; a[5]--; if(a[3] && a[5])y += 2;
    }
    int p = max(max(a[0], a[2]), max(a[3], a[5]));
    //cout << ans << " " << x << " "<< y << endl;
    while(p) {p--; ans += (LL)max(x + 1, y + 1); }
    printf("%I64d\n", ans);
    return 0;
}
