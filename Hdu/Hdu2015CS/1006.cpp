#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
using namespace std;

char s[1010][1010];
int f[1010][1010];
int ans[1010];
int n, m;

int get(int x, int y, int k) {
    return f[x][y] - f[x - k][y] - f[x][y - k] + f[x - k][y - k];
}

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
        memset(f, 0, sizeof f);
        memset(ans, 0, sizeof ans);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) {
                f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
                if(s[i][j] == '1') f[i][j]++;
            }
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) {
                int l = 0, r = min(i, j);
                while(l < r) {
                    int mid = (l + r + 1) / 2;
                    if(get(i, j, mid) == mid * mid) l = mid;
                    else r = mid - 1;
                }
                ans[l]++;
            }
        for(int i = n; i >= 0; i--) ans[i] += ans[i + 1];
        for(int i = 0; i < m; i++)
        {
            int p; scanf("%d", &p);
            printf("%d\n", ans[p]);
        }
    }
    return 0;
}
