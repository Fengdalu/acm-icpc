#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 200000
#define RANGE(LB, VAL, UB) ((LB) <= (VAL) && (VAL) < (UB))
#define LL long long

LL qpow(LL x, int y)
{
    LL ans = 1;
    while(y)
    {
        if(y & 1) ans *= x;
        y /= 2; x *= x;
    }
    return ans;
}

LL s[N];
int a[N], n;
LL ans;

LL IT(LL l, LL r)
{
    return (l + r) * (r - l + 1) / 2;
}

LL p = 0;
LL cal(LL B)
{
    int r = 0;
    LL cnt = 0;
    int cc = 0;
    for(int l = 0; l <= n; l++)
    {
        while(s[r] - s[l] < B && r < n) r++;
        if(s[r] - s[l] >= B)
        {
            cc += (r - l - 1);
            cnt += (LL)(l + 1) * (r - l - 1) + (LL)(l + r) * (r - l - 1) / 2;
        }
        else
        {
            cc += r - l;
            cnt += (LL)(l + 1) * (r - l) + (LL)(l + 1 + r) * (r - l) / 2;
        }
//        cout << l << " " << r << " " << cc << endl;
    }
//    cout << B << " " << cc << endl;
//    for(int i = 0; i <= n; i++) cout << pre[i] << " "; cout << endl;
    LL res = cnt - p;
    p = cnt;
//    cout << res << endl;
    return res;
}

int main()
{
//    freopen("1006.in", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int _T; scanf("%d", &_T);
    while(_T--)
    {
        scanf("%d", &n);
        a[0] = 0; for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        s[0] = 0; for(int i = 1; i <= n; i++) s[i] = s[i - 1] + (LL)a[i];

        ans = 0;
        p = 0;
        for(int k = 1; k <= 40; k++)
        {
            ans += (LL)cal(qpow(2, k)) * (LL)(k - 1);
//            cout << endl;
        }
//        cout << ans << endl;
        ans += (LL)(n) * (LL)(n + 1) * (LL)(n + 1) / 2;
        //for(int i = 1; i <= n; i++) ans += i * (n - i + 1) + (n + i) * (n - i + 1) / 2;
        printf("%I64d\n", ans);
    }
    return 0;
}
