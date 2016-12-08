#include <bits/stdc++.h>

using namespace std;
const int N = 20;
vector<int> cal(int w[], int n, int ac[], int m) {
    vector<int> ans;
    vector<int> vis(1 << n, 0);
    vis[0] = true;
    for(int mk = 0; mk < (1 << n); mk++) {
        vis[mk] = true;
        for(int i = 0; i < n; i++)
            if(mk >> i & 1) vis[mk] &= vis[mk ^ (1 << i)];
        int tot = 0;
        for(int i = 0; i < m; i++)
            if(mk & ac[i]) tot++;
        if(__builtin_popcount(mk) > tot) vis[mk] = false;
        if(vis[mk]) {
            int s = 0;
            for(int i = 0; i < n; i++)
                if(mk >> i & 1) s += w[i];
            ans.push_back(s);
        }
    }
    puts("");
    sort(ans.begin(), ans.end());
    return ans;
}

int l[N], r[N];
int a[N], b[N];
int n, m;
char s[1000];


int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%s", s);
        for(int j = 0; j < m; j++) if(s[j] == '1') {
            r[j] |= (1 << i);
            l[i] |= (1 << j);
        }
    }
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    for(int i = 0; i < m; i++) scanf("%d", b + i);

    int t; scanf("%d", &t);
    vector<int> p = cal(a, n, r, m), q = cal(b, m, l, n);
    sort(q.begin(), q.end());
    sort(p.begin(), p.end());
    long long ans = 0;
    for(int x: p) {
        ans += q.end() - lower_bound(q.begin(), q.end(), t - x);
    }
    printf("%I64d\n", ans);
    return 0;
}
