#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 100010
#define PII pair<int, int>
#define MP(i, j) make_pair(i, j)
#define AA first
#define BB second

int a[N];
struct p
{
    int sum, id;
    bool operator < (const p& b) const
    {
        return sum < b.sum;
    }
}f[N];
int n, k;

int main()
{
//    freopen("input.txt", "r", stdin);
    while(~scanf("%d%d", &n, &k))
    {
        if(!n && !k) break;

        a[0] = 0;
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        memset(f, 0, sizeof f);
        for(int i = 1; i <= n; i++) f[i].sum = f[i - 1].sum + a[i];
        for(int i = 0; i <= n; i++) f[i].id = i;
        n++;
        sort(f, f + n);
//        for(int i = 1; i <= n; i++) cout << f[i].id << " " << f[i].sum << endl; cout << endl;

        while(k--)
        {
            int l = 0, r = 1;
            int q; scanf("%d", &q);
            PII R = MP(f[l].id, f[r].id);
            int m = abs(f[r].sum - f[l].sum);
            while(r < n)
            {
                int s = abs(f[r].sum - f[l].sum);
                if( abs(m - q) > abs(s - q) ) { m = s; R = MP(f[l].id, f[r].id); }
                if(s < q) r++;
                else l++;
                if(l == r) r++;
            }
            printf("%d %d %d\n", m, min(R.AA, R.BB) + 1, max(R.AA, R.BB));
        }

    }
    return 0;
}

