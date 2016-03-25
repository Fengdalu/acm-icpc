#include<cstdio>
#include<cmath>
#include<set>
#include<algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

long long sum[3];
int num[22];
int n;
//const int MOD = 10000007;
int cnt;


int hefa()
{
    if(sum[0] + sum[1] <= sum[2]) return 0;
    if(sum[2] + sum[0] <= sum[1]) return 0;
    if(sum[2] + sum[1] <= sum[0]) return 0;
    return 1;
}
set<long long> S;
void add()
{
    S.insert((sum[0] << 20LL) | sum[1]);
}
void dfs(int pos)
{
    if(pos==n)
    {
        if(sum[0] >= sum[1] && sum[1] >= sum[2] && hefa()) {
            add();
        }
        return;
    }
    sum[0]+=num[pos];
    dfs(pos+1);
    sum[0]-=num[pos];
    sum[1]+=num[pos];
    dfs(pos+1);
    sum[1]-=num[pos];
    sum[2]+=num[pos];
    dfs(pos+1);
    sum[2]-=num[pos];
}
int main()
{
    //freopen("K.in", "r", stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(sum, 0, sizeof sum);
        scanf("%d",&n);
        cnt = 0;
        for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
        S.clear();
        dfs(0);
        //sort(s, s + cnt);
        //printf("%d\n", unique(s, s + cnt) - s);
        int ans = S.size();
        printf("%d\n", ans);
    }
    return 0;
}
