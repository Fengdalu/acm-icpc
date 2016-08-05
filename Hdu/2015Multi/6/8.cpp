#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MP make_pair
#define AA first
#define BB second

typedef long long ll;
const long long mod=1e9+7;
long long inv[100010];
long long fac[100010];
long long ifac[100010];
void init()
{
    inv[0]=fac[0]=ifac[0]=1;
    inv[1]=fac[1]=ifac[1]=1;
    for(int i=2;i<10000;i++)
    {
        fac[i]=fac[i-1]*i%mod;
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
        ifac[i]=ifac[i-1]*inv[i]%mod;
    }
}
long long C(long long n,long long m)
{
    if(m>n)return 0;
    if(n < 0 || m < 0) return 0;
    return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}

void update(int &a, int b) {
    a = (a + b) % mod;
}


int dp[1010][1010];
typedef pair<int, int> PII;
pair<PII, int> q[1000100][2];
bool vis[1010][1010][2];
int cnt[2];

int main() {
    init();
    int _T;
    scanf("%d", &_T);
    while(_T--) {
        int n, s;
        scanf("%d%d", &n, &s);
        memset(dp, 0, sizeof dp);
        int x=0, y=1;
        cnt[0] = cnt[1] = 0;
        dp[0][0] = 1;
        vis[0][0][x] = true;
        q[cnt[x]++][x] = MP(MP(0, 0), 1);
        for(int i = 0; i < n; i++) {
            for(int i = 0; i < cnt[x]; i++) {
                int a = q[i][x].AA.AA, b = q[i][x].AA.BB;
                dp[a][b] = 0;
            }
            int w; scanf("%d", &w);
            cnt[y] = 0;
            for(int i = cnt[x] - 1; i >= 0; i--) {
                int a = q[i][x].AA.AA, b = q[i][x].AA.BB;
                if(!vis[a][b][x]) continue;
                if(a + w <= s)
                update(dp[a + w][b + 1], q[i][x].BB);
                update(dp[a][b], q[i][x].BB);

                if(a + w <= s)
                q[cnt[y]++][y] = MP(MP(a + w, b + 1), dp[a + w][b + 1]);
                if(a + w <= s)
                vis[a + w][b + 1][y] = true;

                q[cnt[y]++][y] = MP(MP(a, b), dp[a][b]);
                vis[a][b][x] = false;
                vis[a][b][y] = true;
            }
            swap(x, y);
        }

        int ans = 0;
        for(int i = 0; i <= s; i++)
            for(int j = 0; j <= n; j++) {
                update(ans, dp[i][j] * C(j, 2) % mod * 4 % mod * C(n - j, 2) % mod);
            }
        cout << ans << endl;
    }
    return 0;
}
