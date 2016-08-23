#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cassert>
using namespace std;
#define ONES(x) __builtin_popcount(x) // `1数目`

//枚举C(n, k)所有可能, 复杂度O(C(n, k))
int next_combination(int n, int k) {
    int ret, b = k & -k, t = (k + b);
    ret = (((t ^ k) >> 2) / b) | t;
    if (ret >= (1 << n)) return 0;
    return ret;
}

int ww[30], idw[30];
int wg[30], idg[30];
int w[30], g[30], idf[30];
char buf[100000], buf1[100000];
int u[600], v[600], c[600];
const int inf = 1e9 + 7;
inline int run() {
    int n = 0, k = 8;
    unordered_map<string, int>mp;
    int cnt = 0;
    int cnt1 = 0;
    for(int i = 0; i < 23; i++) {
        int t;
        if(scanf("%s", buf) != 1) return 0;
        mp[string(buf)] = i;
        scanf("%d", &t);
        scanf("%s", buf1);
        if(buf1[0] == 's') ww[cnt] = t, idw[cnt] = i, cnt++;
        else if(buf1[0] == 'g') wg[cnt1] = t, idg[cnt1] = i, cnt1++;
        else {
            w[n] = t;
            g[n] = buf1[0];
            idf[n] = i;
            n++;
        }
    }
    int m; scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%s%s%d", buf, buf1, &c[i]);
        u[i] = mp[string(buf)];
        v[i] = mp[string(buf1)];
    }
    int ans = -inf;
    //cout << cnt << " " << cnt1 << " " << n << endl;
    for(int i = 0; i < n; i++) assert(g[i] == 'd' || g[i] == 'm');
    if(n < 8) {
        printf("impossible\n");
        return 1;
    }
    for(int i = 0; i < cnt1; i++)
        for(int j = 0; j < cnt; j++)
            for(int k = j + 1; k < cnt; k++) {
                int mk = 1 << idg[i] | 1 << idw[j] | 1 << idw[k];
                int ik = (1 << 8) - 1;
                do {
                    unordered_map<char, int>f;
                    int tp = mk;
                    int tot = wg[i] + ww[j] + ww[k];
                    for(int i = 0; i < n; i++) {
                        if(1 << i & ik) {
                            tp |= 1 << idf[i];
                            f[g[i]]++;
                            tot += w[i];
                        }
                    }
                    for(int i = 0; i < m; i++)
                        if(1 << u[i] & tp) if(1 << v[i] & tp) tot += c[i];
                    if(f['d'] == 4 && f['m'] == 4) ans = max(ans, tot);
                } while(ik = next_combination(n, ik));
            }
    if(ans == -inf)  printf("impossible\n");
    else printf("%d\n", ans);
    return 1;
}

int main() {
    while(run());
    return 0;
}
