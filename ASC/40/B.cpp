#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

const int maxn = 303000;
int sa[maxn];
int wa[maxn], wb[maxn], wv[maxn], wd[maxn];

int cmp(int *r, int a, int b, int l)
{
    return r[a]==r[b] && r[a+l]==r[b+l];
}

void getsa(int *r, int n, int m)
{
    int i, j, p, *x = wa, *y = wb, *t;
    for(i = 0; i < m; i++) wd[i] = 0;
    for(i = 0; i < n; i++) wd[x[i]=r[i]]++;
    for(i = 1; i < m; i++) wd[i] += wd[i-1];
    for(i = n-1; i >= 0; i--) sa[--wd[x[i]]] = i;
    for(j = 1, p = 1; p < n; j*=2, m = p)
    {
        for(p = 0, i = n-j; i < n; i++) y[p++] = i;
        for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i]-j;
        for(i = 0; i < n; i++) wv[i] = x[y[i]];
        for(i = 0; i < m; i++) wd[i] = 0;
        for(i = 0; i < n; i++) wd[wv[i]]++;
        for(i = 1; i < m; i++) wd[i] += wd[i-1];
        for(i = n-1; i >= 0; i--) sa[--wd[wv[i]]] = y[i];
        for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p-1 : p++;
    }
}

int n, m; //字符串长度，字符范围（要稍大一点）
int r[maxn]; //待处理的串
int an[maxn];

int main()
{
    freopen("binary.in","r",stdin);
    freopen("binary.out","w",stdout);
    while(~scanf("%d",&n))
    {
        memset(sa,1,sizeof(sa));
        memset(wa,1,sizeof(wa));
        memset(wb,1,sizeof(wb));
        memset(wv,1,sizeof(wv));
        memset(wd,1,sizeof(wd));
        memset(r,1,sizeof(r));
        memset(sa,1,sizeof(sa));
        int flg = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&an[i]);
        }
        int div;
        for(int i = 1; i <= n; i++)
        {
            if(an[i] != n+1-i)
            {
                div = n+1-i;
                break;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            if(an[i] == div)
            {
                flg = 1;
            }
            r[an[i]-1] = flg;
        }
        r[n] = 0;
        getsa(r,n+1,3);
        flg = 1;
        for(int i = 1; i <= n; i++)
        {
            if(sa[i]+1 != an[i])
            {
                flg = 0;
                break;
            }
        }
        if(flg == 0) printf("Error\n");
        else
        {
            for(int i = 0; i < n; i++) printf("%d",r[i]);
            printf("\n");
        }
    }
    return 0;
}

/*
7
7 4 5 2 6 3 1
6
1 2 4 6 3 5

ll dp[50][2], pr[30] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
73, 79, 83, 89, 97, 101, 103, 107, 109, 113};

ll ab(ll a)
{
    return a > 0 ? a : -a;
}

int main()
{
    dp[1][0] = 1;
    dp[1][1] = 2;
    dp[2][0] = 2;
    dp[2][1] = 3;
    for(int i = 3; i <= 30; i++)
    {
        if()
    }
    return 0;
}
*/