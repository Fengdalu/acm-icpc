#include <bits/stdc++.h>
using namespace std;

const int maxn = 200100;
const int maxp = 21;
typedef long long ll;
int n;
int f[maxn][maxp], g[maxn][maxp];
int a[maxn], b[maxn];
int p[maxn];

void make() {
    p[0] = -1;
    for(int i = 1; i < maxn; i++) p[i] = p[i - 1] + ((i & (i - 1)) == 0);
    for(int i = 0; i < maxn; i++) {
        f[i][0] = a[i];
        g[i][0] = b[i];
    }
    for(int j = 1; j < maxp; j++)
        for(int i = 0; i < n; i++)
            if(i + (1 << j) <= n) {
                f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
                g[i][j] = min(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
            }
}

int q1(int l, int r) {
    int w = p[r - l + 1];
    return max(f[l][w], f[r - (1 << w) + 1][w]);
}

int q2(int l, int r) {
    int w = p[r - l + 1];
    return min(g[l][w], g[r - (1 << w) + 1][w]);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);
    make();
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int l = i, r = n - 1;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(q1(i, mid) > q2(i, mid)) r = mid - 1;
            else l = mid;
        }
        if(q1(i, l) != q2(i, l)) continue;
        int r1 = r;
        l = i; r = n - 1;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(q1(i, mid) < q2(i, mid)) l = mid + 1;
            else r = mid;
        }
        ans += (r1 - r + 1);
    }
    cout << ans << endl;
    return 0;
}
