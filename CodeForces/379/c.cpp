#include <bits/stdc++.h>

typedef long long LL;
const int N = 2e5+1000;
std::pair<LL, LL> Q[N], F[N];
LL a[N], b[N], c[N], d[N];

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int x, s;
    scanf("%d%d", &x, &s);
    for(int i = 0; i < m; i++) scanf("%I64d", a + i);
    for(int i = 0; i < m; i++) scanf("%I64d", b + i);

    for(int i = 1; i <= k; i++) scanf("%I64d", c + i);
    for(int i = 1; i <= k; i++) scanf("%I64d", d + i);
    k++;
    c[0] = 0; d[0] = 0;
    int cnt = 0;
    for(int i = 0; i < m; i++) Q[cnt++] = std::make_pair(b[i], a[i]);
    Q[cnt++] = std::make_pair(0, x);
    std::sort(Q, Q + cnt);

    int L = 0;
    for(int i = 0; i < cnt; i++) {
        if(L == 0 || Q[i].second < F[L - 1].second)
            F[L++] = Q[i];
    }

    LL ans;
    bool flag = false;
    for(int i = 0; i < k; i++) {
        int p = std::upper_bound(F, F + L, std::make_pair(s - d[i], (LL)2e9)) - F;
        p--;
        if(p != -1) {
            LL t = F[p].second * (n - c[i]);
            if(!flag || t < ans) {
                flag = true;
                ans = t;
            }
        }
    }
    printf("%I64d\n", ans);
    return 0;
}
