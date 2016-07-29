#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
#define PB(x) push_back(x)
#define SZ size()

inline int lb(int x) { return x & (-x); }

typedef pair<int, int> PII;
int main() {
    int _T, cas = 1;
    scanf("%d", &_T);
    while(_T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<PII>e(m, PII(0, 0));
        vector<int>g(1 << n, 0);
        vector<int>sum(1 << n, 0);
        vector<bool>vis(1 << n, 0);
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &e[i].AA, &e[i].BB);
            g[1 << e[i].AA] |= 1 << e[i].BB;
            g[1 << e[i].BB] |= 1 << e[i].AA;
        }
        for(int i = 1; i < (1 << n); i++) g[i] = g[i ^ lb(i)] | g[lb(i)];
        queue<int>q;
        for(int i = 0; i < n; i++) q.push(1 << i);
        for(int i = 0; i < n; i++) vis[1 << i] = true;
        while(q.SZ) {
            int cur = q.front(); q.pop();
            int mk = g[cur] ^ (g[cur] & cur);
            for(int i = mk; i; i ^= lb(i)) {
                int cc = lb(i);
                if(!vis[cc ^ cur]) {
                    q.push(cc ^ cur);
                    vis[cc ^ cur] = true;
                }
            }
        }
        int tot = 0;
        for(int i = 0; i < (1 << n); i++) {
            int mk = (1 << n) - 1;
            if(vis[i] && vis[mk ^ i])  tot++, sum[i]++;
        }
        for(int j = 0; j < n; j++)
        for(int i = (1 << n) - 1; i >= 0; i--) {
            if(1 << j & ~i) sum[i] += sum[i | (1 << j)];
        }
        tot /= 2;
        printf("Case #%d:", cas++);
        for(int i = 0; i < m; i++) printf(" %d", tot - sum[1 << e[i].AA | 1 << e[i].BB]);
        printf("\n");
    }
    return 0;
}
