#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
unsigned qpow(unsigned a, unsigned b) {
    unsigned ans = 1;
    while(b) {
        if(b & 1) ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}

char buf[100];
int q[18];
int c[18][18];
int ans[1 << 18];
int f[1 << 18][18];
int n;
int main() {
    int _T; scanf("%d", &_T);
    while (_T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", buf);
            for(int j = 0; j < n; j++)  c[i][j] = buf[j] - '0';
        }
        unsigned ANS = 0;
        ans[0] = 0;
        memset(f, 0, sizeof f);
        for(int mk = 1; mk < (1 << n); mk++) {
            int u = 0;
            ans[mk] = n + 1;
            for(u = 0; u < n; u++) if(1 << u & mk) {
                int cnt = 0;
                int w = mk ^ 1 << u;
                for(int i = 0; i < n; i++) if(1 << i & w) if(c[u][i]) q[cnt++] = f[w][i];
                sort(q, q + cnt);
                cnt = unique(q, q + cnt) - q;
                int J = 1;
                for(int i = 0; i < cnt; i++) {
                    if(q[i] != J) {
                        break;
                    }
                    else J++;
                }
                if(q[cnt - 1] == J) J++;
                int t = max(ans[w], J);
                if(t < ans[mk]) {
                    for(int i = 0; i < n; i++) if(1 << i & mk) f[mk][i] = f[w][i];
                    //cout << "NODE ";for(int i = 0; i < n; i++) if(1 << i & mk)  cout << i << " "; cout << endl;
                    f[mk][u] = J;
                    //cout << "NODE ";for(int i = 0; i < n; i++) if(1 << i & mk) cout << f[mk][i] << " "; cout << endl;
                    ans[mk] = min(ans[mk], max(ans[w], J));
                }
            }
            //cout << mk << " " << ans[mk] << endl;
            ANS += (unsigned)(ans[mk]) * qpow(233, mk);
        }
        printf("%u\n",ANS);
    }
    return 0;
}
