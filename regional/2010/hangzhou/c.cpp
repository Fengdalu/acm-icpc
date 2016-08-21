#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
typedef long long ll;
#define MP make_pair
#define AA first
#define BB second

const int N = 1010;
int X[N], Y[N];
char buf[N];
bool vis[N][N];
pair<int, PII> q[N];
int main() {
    int n, m;
    int _t; scanf("%d", &_t);
    while(_t--) {
        scanf("%d%d", &n, &m);
        int tot = 0;
        memset(X, 0, sizeof X);
        memset(Y, 0, sizeof Y);
        memset(vis, 0, sizeof vis);
        int add = 0;
        while(m--) {
            char ch1, ch2;
            int v1, v2;
            scanf("%s", buf);
            sscanf(buf, "%c=%d,%c=%d", &ch1, &v1, &ch2, &v2);
            if(ch1 > ch2) {
                swap(ch1, ch2);
                swap(v1, v2);
            }
            if(ch1 == 'X' && ch2 == 'Y') {
                if(!vis[v1][v2]) X[v1]++, Y[v2]++, add++;
                vis[v1][v2] = true;
            }
            else if(ch1 == 'X') {
                q[tot++] = MP(v2, MP(v1, 0));
            }
            else
                q[tot++] = MP(v2, MP(v1, 1));
        }
        sort(q, q + tot);
        tot = unique(q, q + tot) - q;
        int NX = 0, NY = 0;
        int CX = 0, CY = 0;
        int ans = 0;
        int pre = 0;
        for(int i = 0; i < tot; i++) {
            if(q[i].BB.BB == 0) { NX++; CX+=X[q[i].BB.AA]; }
            else { NY++; CY+=Y[q[i].BB.AA]; }
            if(i == tot - 1 || q[i].AA != q[i + 1].AA) {
                ans += NX * n + NY * n - NX * NY;
                ans -= CX + CY;
                for(int j = pre; j <= i; j++)
                    for(int k = pre + 1; k <= i; k++) {
                        if(q[j].BB.BB == 0 && q[k].BB.BB == 1) {
                            int x = q[j].BB.AA, y = q[k].BB.AA;
                            if(vis[x][y]) {
                                ans++;
                            }
                        }
                    }
                CX = CY = NX = NY = 0;
                pre = i + 1;
            }
        }
        printf("%d\n", ans + add * n);
    }
    return 0;
}
