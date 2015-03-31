#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int N = 1005;

int m, n;
char s[N][N];
int x[N * N], y[N * N];
int f[N][N];

const int X[4] = {1, -1, 0, 0};
const int Y[4] = {0, 0, 1, -1};


int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> s[i] + 1;
    for(int i = 0; i <= n + 1; i++) for(int j = 0; j <= m + 1; j++)
        if(i == n + 1|| i == 0 || j == 0 || j == m + 1) s[i][j] = 'T';

    memset(f, 0, sizeof f);
    int l = 0, r = -1;
    for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++)
    if(s[i][j] == 'E'){ r++; x[r] = i; y[r] = j; f[i][j] = 1; break; }

    while(l <= r)
    {
        int xx = x[l], yy = y[l], cc = f[xx][yy]; l++;
        for(int i = 0; i < 4; i++)
        {
            int p = xx + X[i], q = yy + Y[i];
            if(s[p][q] != 'T' && f[p][q] == 0)
            {
                r++;
                x[r] = p; y[r] = q; f[p][q] = cc + 1;
            }
        }
    }
    int b = 0;
    for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++)
    if(s[i][j] == 'S'){ b = f[i][j]; break; }

    int ans = 0;
    for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++)
    if(f[i][j] != 0 && f[i][j] <= b && '0' <= s[i][j] && s[i][j] <= '9')
        ans += (s[i][j] - '0');

    cout << ans << endl;
    return 0;
}
