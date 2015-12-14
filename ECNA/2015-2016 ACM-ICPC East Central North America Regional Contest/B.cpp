#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define PII pair<int, int>
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
#define cmin(x, y) x = min(x, y)
const int Maxn = 300;
int X[Maxn], Y[Maxn];
int cntx, cnty;
int n, m;
int r, c;
PII st[Maxn];
int s1[Maxn][Maxn], s2[Maxn][Maxn];


int sub(int x1, int y1, int x2, int y2, int s[Maxn][Maxn]) {
    return s[x2][y2] + s[x1][y1] - s[x1][y2] - s[x2][y1];
}

int main() {
   // freopen("input.in", "r", stdin);
    scanf("%d%d%d%d", &r, &c, &n, &m);
    for(int i = 0; i < n; i++) scanf("%d%d", &st[i].AA, &st[i].BB);
    for(int i = n; i < n + m; i++) scanf("%d%d", &st[i].AA, &st[i].BB);
    for(int i = 0; i < n + m; i++) {
        st[i].AA = (2 * st[i].AA + 9);
        st[i].BB = (2 * st[i].BB - 15);
    }

    cntx = cnty = 0;
    for(int i = 0; i < n + m; i++) {
        X[cntx++] = st[i].AA;
        Y[cnty++] = st[i].BB;
    }
    X[cntx++] = (0 + 9);
    Y[cnty++] = (0 + 15);
    X[cntx++] = (n + n - 9);
    Y[cnty++] = (m + m - 15);

    X[cntx++] = 0;
    Y[cnty++] = 0;
    sort(X, X + cntx);
    cntx = unique(X, X + cntx) - X;
    sort(Y, Y + cnty);
    cnty = unique(Y, Y + cnty) - Y;

    for(int i = 0; i < cntx; i++)
        for(int j = 0; j < cnty; j++)
            for(int k = 0; k < n + m; k++)
            if(st[k].AA <= X[i] && st[k].BB <= Y[j]) {
                if(k < n) s1[i][j]++;
                else s2[i][j]++;
            }


    int ans = n + m;
    for(int i = 0; i < cntx; i++) for(int j = i; j < cntx; j++)
    for(int k = 0; k < cnty; k++) for(int p = k; p < cnty; p++) {
        if(X[i] < 9 && n + n - 9 <= X[j])
            if(Y[k] < 15 && m + m - 15 <= Y[p]) continue;
        cmin(ans, n - sub(i, k, j, p, s1) + sub(i, k, j, p, s2));
    }
    printf("%d\n", ans);
    return 0;
}
