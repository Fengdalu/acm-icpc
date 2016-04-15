#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 70;
const int maxm = 210;
const long long mod = 1e9 + 7;
long long f[maxn][maxm][maxm][2];
int n, m, p;

int bit(int x) {
    int ans = 1;
    while(x /= 10) ans++;
    return ans;
}

void add(long long &a, long long b) {
    a = (a + b) % mod;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &m, &p);

    memset(f, 0, sizeof f);
    for(int i = 0; i < m; i++) {
        f[bit(i)][i][0][0] = 1;
        for(int j = 1; j <= n; j++) {
            add(f[bit(i) + j][i][j][0], 1);
        }
    }
    for(int i = 0; i <= n; i++) {
        for(int p = 0; p <= n; p++)
            for(int j = 0; j < m; j++)
            if(f[i][j][p][0] != 0 || f[i][j][p][1] != 0) {
                for(int k = 0; k < m; k++) {
                    int c = bit(k);
                    add(f[i + 1 + c][(k + j) % m][p][0], f[i][j][p][0]);
                    add(f[i + 1 + c][(j - k + m) % m][p][0], f[i][j][p][0]);
                    add(f[i + c][(k + j) % m][p][0], f[i][j][p][1]);
                    add(f[i + c][(j - k + m) % m][p][0], f[i][j][p][1]);
                }
                add(f[i + 2][j][p + 1][1], f[i][j][p][0]);
                if(p) {
                    add(f[i + 1][j][p - 1][0], f[i][j][p][0]);
                }
                add(f[i + 1][j][p + 1][1], f[i][j][p][1]);
            }
    }
    cout << f[n][p][0][0] << endl;
    return 0;
}
