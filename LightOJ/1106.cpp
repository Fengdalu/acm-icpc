#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define N 50
#define LL long long
LL dp[N][500];
LL pre[N][500];
LL fish[N][200];
LL f[N], d[N], t[N];
int n, h;
vector<int>ans;

int main()
{
    //freopen("1106.in", "r", stdin);
    int _T; scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS++)
    {
        scanf("%d", &n);
        scanf("%d", &h);
        for(int i = 0; i < n; i++) scanf("%lld", &f[i]);
        for(int i = 0; i < n; i++) scanf("%lld", &d[i]);
        for(int i = 0; i < n - 1; i++) scanf("%lld", &t[i]);
        h *= 12;
        memset(fish, 0, sizeof fish);
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j <= h; j++)
                fish[i][j] = max(0LL, f[i] - (LL)(j - 1) * d[i]);
            for(int j = 1; j <= h; j++)
                fish[i][j] += fish[i][j - 1];
        }

        memset(dp, -1, sizeof dp);
        memset(pre, -1, sizeof pre);

        for(int i = 0; i <= h; i++) dp[0][i] = fish[0][i];
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= h; j++)
                for(int k = 0; k <= h; k++)
                if(j - k - t[i - 1] >= 0)
                    if(dp[i - 1][j - k - t[i - 1]] >= 0 && dp[i - 1][j - k - t[i - 1]] + fish[i][k] > dp[i][j])
                    {
                        pre[i][j] = k;
                        dp[i][j] = dp[i - 1][j - k - t[i - 1]] + fish[i][k];
                    }
        }
        int ansi = 0;
        for(int i = 0; i < n; i++)
        if(dp[i][h] >= 0 && dp[i][h] > dp[ansi][h])
        {
            ansi = i;
        }
        ans.clear();
        int j = h;
        for(int i = ansi; i > 0; i--)
        {
            ans.push_back(pre[i][j]);
            j = j - pre[i][j] - t[i - 1];
        }
        ans.push_back(j);
        reverse(ans.begin(), ans.end());
        while(ans.size() < n) ans.push_back(0);
        printf("Case %d:\n", CAS);
        for(int i = 0; i < ans.size(); i++)
        if(i != 0) printf(", %d", ans[i] * 5);
        else printf("%d", ans[i] * 5);
        printf("\nNumber of fish expected: %lld\n", dp[ansi][h]);
    }
    return 0;
}
