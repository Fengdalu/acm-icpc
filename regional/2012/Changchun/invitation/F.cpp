#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define FOR(i,x) for(int i = 0, CalfCamel__END__ = (int)(x); i < CalfCamel__END__; i++)
#define FORR(i,x) for(int i = 1, CalfCamel__END__ = (int)(x); i <= CalfCamel__END__; i++)
#define REP(i,y,x) for(int i = (int)(y), CalfCamel__END__ = (int)(x); i <= CalfCamel__END__; i++)
using namespace std;
const int MAXN = 1055;
int dp[MAXN][1 << 8];
int a[MAXN];
int n;
int b[MAXN];
int main()
{
    while(~scanf("%d",&n))
    {
        FORR(i,n) scanf("%d",&a[i]);
        reverse(a + 1, a + n + 1);
        FORR(i,50) a[n + i] = -1;
        memset(dp, 0, sizeof dp);
        dp[1][0] = 1;
        int cnt;
        int nxt;
        int nxtmask;
        int tmp;
//        FORR(i,n + 20) printf("%d ", a[i]);
//        puts(" ");
        FORR(i,n) FOR(mask,1 << 8) if(dp[i][mask])
        {
//            printf("now %d %d:\n",i,mask);
            FORR(k,20) b[i + k] = 0;
            FOR(k,8) if(mask & (1 << k)) b[i + k + 1] = -1;
            cnt = 0;
            FORR(k,20) if(b[i + k] == 0) b[i + k] = ++cnt;
            FORR(k,20) if(b[i + k] != -1 && b[i + k] < 6 && a[i + k] == a[i])
            {
                tmp = b[i + k];
                b[i + k] = -1;
                FORR(p,20) if(b[i + p] != -1)
                {
                    nxt = i + p;
                    break;
                }
                nxtmask = 0;
                FOR(p,8) if(b[nxt + 1 + p] == -1) nxtmask += 1 << p;
                dp[nxt][nxtmask] = 1;
//                printf("\t%d %d\n",nxt, nxtmask);
                b[i + k] = tmp;
            }
        }
        printf("%d\n",dp[n + 1][0]);
    }
}