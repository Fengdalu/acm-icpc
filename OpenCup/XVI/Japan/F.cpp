#include<stdio.h>
#include<algorithm>
#include<string.h>

#define cmax(a,b) a = std::max(a,b);
#define clr(a,b) memset(a,b,sizeof (a))
#define FOR(i,x) for(int i = 0, CC__END__CC = (int)(x); i < CC__END__CC; i++)
#define FORR(i,x) for(int i = 1, CC__END__CC = (int)(x); i <= CC__END__CC; i++)
#define REP(i,y,x) for(int i = (int)(y), CC__END__CC = (int)(x); i <= CC__END__CC; i++)
const int MAXN = 205;
const int MAXP = 1005;
int n,m,p;
int d[MAXN][MAXN];
double dp[MAXN][MAXP];
double dp2[MAXN][MAXP];
double w[MAXN][MAXN];
int main()
{
    scanf("%d%d%d",&n,&m,&p);
    int s,t,x,y;
    clr(d,0);
    FOR(i,m)
    {
        scanf("%d%d%d%d",&s,&t,&x,&y);
        s--;t--;
        d[s][t] = d[t][s] = x;
        w[s][t] = w[t][s] = (double) y / (double) x;
    }
    FOR(i,n) REP(j,0,p) dp[i][j] = -1.0;
    dp[0][0] = 0;
    int up;
    double tmp;
    FOR(t,p) FOR(st,n) if(dp[st][t] != -1.0) FOR(ed,n) if(d[st][ed])
    {
        up = t + d[st][ed];
        if(up < p)
        {
            tmp = dp[st][t] + w[st][ed] * d[st][ed];
            if(dp[ed][up] == -1.0) dp[ed][up] = tmp;
            else cmax(dp[ed][up], tmp);
        }
    }
    //FOR(i,n) REP(j,0,p) printf("%d %d %.5lf\n", i , j , dp[i][j]);
    FOR(i,n) REP(j,0,p) dp2[i][j] = -1.0;
    FOR(t1,p) FOR(t2,p) if(t1 + t2 <= p) FOR(ed,n) if(dp[ed][t1] != -1.0 && dp[ed][t2] != -1.0)
    {
        tmp = dp[ed][t1] + dp[ed][t2];
        if(dp2[ed][t1 + t2] == -1.0) dp2[ed][t1 + t2] = tmp;
        else cmax(dp2[ed][t1 + t2], tmp)
    }
    double ans = 0;
    FOR(i,n) cmax(ans, dp2[i][p]);
    FOR(st, n) FOR(ed, n) if(d[st][ed]) FOR(t, p) if(dp2[st][t] != -1.0)
    {
        cmax(ans, dp2[st][t] + w[st][ed] * (p - t));
        //printf("UP  %d %d %d %.5f\n",st,ed,p, ans);
    }
    //FOR(i,n) REP(j,0,p) printf("%d %d %.5lf\n", i , j , dp2[i][j]);
    printf("%.8f\n",ans);
}
