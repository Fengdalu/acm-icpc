#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

#define clr(a,b) memset(a,b,sizeof(a))
#define FORR(x,y) for(int x = 1, __END__ = (int)(y); x <= __END__; x++)
#define FOR(x,y) for(int x = 0, __END__ = (int)(y); x < __END__; x++)

const long long MOD = 1000000000 + 7;

long long dp[2][100005];

typedef std::pair<int, int> pii;
typedef std::pair<pii, int> piii;

#define MP3(x,y,z) std::make_pair(std::make_pair(x,y),z)
#define MP(x,y) std::make_pair(x,y)
#define PB(x) push_back(x)
#define all(x) x.begin(),x.end()
#define AA first
#define X first.first
#define Y first.second
#define BB second
std::vector<piii> v;
std::vector<pii> vans;
int nowans;
void initans()
{
    nowans = 0;
}
void tryans(int n, int m, int ans)
{
    //if(n <= 100 && m <= 10)
    //    printf("%d %d = %d\n", n,m,ans);
    if(nowans >= v.size())
        return;
    
    while(v[nowans].X < m)
    {
        vans.PB(MP(v[nowans].BB,0));
        nowans++;
        if(nowans >= v.size())
            return;
    }
    
    while(v[nowans].X == m && v[nowans].Y < n)
    {
        vans.PB(MP(v[nowans].BB,0));
        nowans++;
        if(nowans >= v.size())
            return;
    }
    
    while(v[nowans].X == m && v[nowans].Y == n)
    {
        vans.PB(MP(v[nowans].BB,ans));
        nowans++;
        if(nowans >= v.size())
            return;
    }
}

int sum[501];
void gao()
{
    sum[0] = 0;
    FORR(i,500)
    sum[i] = sum[i - 1] + i;
    int n = 100000;
    int m = 1;
    int cur = 0;
    FORR(i,n)
    {
        dp[cur][i] = 1;
        tryans(i,m,1);
    }
    dp[0][0] = 1;
    dp[1][0] = 1;
    for(int m = 2; m <= 500; m++)
    {
        for(int i = sum[m]; i <= n; i++)
        {
            dp[cur ^ 1][i] = dp[cur][i - m];
            if(i - m >= sum[m])
                dp[cur ^ 1][i] += dp[cur ^ 1][i - m];
            while(dp[cur ^ 1][i] >= MOD)
                dp[cur ^ 1][i] -= MOD;
            tryans(i,m,dp[cur ^ 1][i]);
        }
        cur ^= 1;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    int x,y;
    FOR(i,T)
    {
        scanf("%d%d",&x,&y);
        v.PB(MP3(y,x,i));
    }
    std::sort(all(v));
    initans();
    gao();
    while(nowans < v.size())
    {
        vans.PB(MP(v[nowans].BB, 0));
        nowans++;
    }
    std::sort(all(vans));
    FOR(i,T)
    printf("%d\n",vans[i].BB);
}
