#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long
#define N 100010
#define MOD 1000000007

int pos[N];
int a[N];
int l[N], r[N];
int n;

int main()
{
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        for(int i = 0; i < N; i++) pos[i] = -1;
        for(int i = 0; i < n; i++) l[i] = -1;
        for(int i = 0; i < n; i++)
        {
            l[i] = max(l[i], pos[a[i]]);
            for(int j = 1; j * j <= a[i]; j++)
            {
                if(a[i] % j == 0) { l[i] = max(l[i], pos[j]); l[i] = max(l[i], pos[a[i] / j]);}
            }
            l[i]++;
            pos[a[i]] = i;
        }
        for(int i = 0; i < n; i++) r[i] = n;
        for(int i = 0; i < N; i++) pos[i] = n;
        for(int i = n - 1; i >= 0; i--)
        {
            r[i] = min(r[i], pos[a[i]]);
            for(int j = 1; j * j <= a[i]; j++)
            {
                if(a[i] % j == 0) { r[i] = min(r[i], pos[j]); r[i] = min(r[i], pos[a[i] / j]);}
            }
            r[i]--;
            pos[a[i]] = i;
        }
        LL ans = 0;
        /*
        cout << "L: ";
        for(int i = 0; i < n; i++) cout << l[i] << " "; cout << endl;
        cout << "R: ";
        for(int i = 0; i < n; i++) cout << r[i] << " "; cout << endl;
        */
        for(int i = 0; i < n; i++)
        {
            ans = (ans + (LL)(i - l[i] + 1) * (r[i] - i + 1));
            ans %= MOD;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}