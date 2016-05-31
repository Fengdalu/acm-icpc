#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

#define clr(a,b) memset(a,b,sizeof(a))
#define FORR(x,y) for(int x = 1, __END__ = (int)(y); x <= __END__; x++)
#define FOR(x,y) for(int x = 0, __END__ = (int)(y); x < __END__; x++)
#define REP(x,z,y) for(int x = (int)(z), __END__ = (int)(y); x <= __END__; x++)

const long long MOD = 1000000000 + 7;

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

#define ccmin(x,y) {if(x == -1) x = (y); else x = std::min(x,(y));}
int n,k;
std::vector<piii> v;
inline int getx(int x)
{
    if(x == 1) return 1;
    if(x == 2) return 3;
    return 2;
}
long long dp[2][400][400];
int main()
{
    scanf("%d%d",&n,&k);
    int x,y,z;
    FOR(i,n)
    {
        scanf("%d%d%d",&x,&y,&z);
        v.PB(MP3(-y,getx(x),z));
    }
    sort(all(v));
    int cur = 0;
    clr(dp,-1);
    dp[cur][0][0] = 0;
    FOR(l,n)
    {
        //printf("item %d %d %d %d\n", l, v[l].X, v[l].Y, v[l].BB);
        //clr(dp[cur ^ 1], -1);
        dp[cur][0][0] = 0;
        REP(i,0,k) REP(j,0,k) if(~dp[cur][i][j])
        {
            ccmin(dp[cur ^ 1][i][j], dp[cur][i][j]);
            //printf("dp %d %d = %lld\n",i,j,dp[cur][i][j]);
            if(v[l].Y == 1) ccmin(dp[cur ^ 1][i + 1][j], dp[cur][i][j] + v[l].BB);
            if(v[l].Y == 2) ccmin(dp[cur ^ 1][i + 1][j], dp[cur][i][j] + v[l].BB);
            if(v[l].Y == 2 && i > j) ccmin(dp[cur ^ 1][i][j + 1], dp[cur][i][j] + v[l].BB);
            if(v[l].Y == 3 && i > j) ccmin(dp[cur ^ 1][i][j + 1], dp[cur][i][j] + v[l].BB);
            //printf("UPDATE dp %d %d = %lld\n",i + 1, j, dp[cur ^ 1][i + 1][j]);
            //printf("UPDATE dp %d %d = %lld\n",i, j + 1, dp[cur ^ 1][i][j + 1]);
        }
        cur ^= 1;
    }
    printf("%lld\n",dp[cur][k][k]);
}
