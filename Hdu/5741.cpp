#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define MP(x, y) make_pair(x, y)
#define PB(x) push_back(x)
#define AA first
#define BB second

typedef pair<int, int> PII;
int a[1010];
char s[500010];


struct BIT {
    int _[500010 * 2 + 1010];
    int n;
    BIT(){}
    BIT(int n): n(n) {
        for(int i = 0; i <= n; i++) _[i] = 0;
    }
    int LB(int x) { return x & (-x); }
    void update(int x, int w) {
        for(;x <= n; x += LB(x)) { _[x] += w; }
    }
    int cal(int x) {
        int ans = 0;
        for(; x > 0; x -= LB(x)) {
            ans += _[x];
        }
        return ans;
    }
}Y;

int main() {
    int _T;
    scanf("%d", &_T);
    while(_T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);

        vector<pair<PII, PII> >g;
        vector<int>Z;
        for(int i = 0; i < n; i++) {
            int w[2] = {0, 0};
            for(int j = i + 1; j < n; j++) {
                int d[2] = {0, 0};
                d[i & 1] += a[i];
                d[j & 1] += a[j];
                Z.PB(w[0]);
                Z.PB(w[0] + d[0] + 1);
                g.PB(MP(MP(w[1], -2), MP(w[0], w[0] + d[0] + 1)));
                g.PB(MP(MP(w[1] + d[1] + 1, -1), MP(w[0], w[0] + d[0] + 1)));
                w[j & 1] += a[j];
            }
        }
        for(int i = 0; i < m; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            Z.PB(a);
            g.PB(MP(MP(b, i), MP(a, a)));
        }
        sort(g.begin(), g.end());
        sort(Z.begin(), Z.end());
        Z.resize(unique(Z.begin(), Z.end()) - Z.begin());
        for(int i = 0; i <= Z.size(); i++) Y._[i] = 0;
        Y.n = Z.size() + 1;
        for(int i = 0; i < g.size(); i++) {
            int a = g[i].BB.AA, b = g[i].BB.BB;
            int op = g[i].AA.BB;
            a = lower_bound(Z.begin(), Z.end(), a) - Z.begin() + 1;
            b = lower_bound(Z.begin(), Z.end(), b) - Z.begin() + 1;
            if(op == -2) {
                Y.update(a, 1);
                Y.update(b, -1);
            }
            else if(op == -1) {
                Y.update(a, -1);
                Y.update(b, 1);
            }
            else {
                s[op] = Y.cal(a) > 0 ?  '1' : '0';
            }
        }
        s[m] = 0;
        printf("%s\n", s);
    }
    return 0;
}

