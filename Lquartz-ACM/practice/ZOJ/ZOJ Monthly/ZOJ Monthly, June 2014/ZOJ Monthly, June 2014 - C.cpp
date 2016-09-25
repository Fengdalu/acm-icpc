#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define OP begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)

const double eps = 1e-8;
const LL MOD = 1000000007;
#define N 111111
int n, k;
int g[N], pre[N], next[N];
int now[N], cnt[N], fi[N];
map<int, int> mp;
int tot;


int main() {
    int i, j;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    while(scanf("%d%d", &n, &k) != EOF) {
        tot = 1;
        mp.clear();
        for(i = 1; i <= n; i++) {
            scanf("%d", &j);
            if(mp[j] == 0) {
                mp[j] = tot++;
            }
            g[i] = mp[j];
        }
        for(i = 1; i < tot; i++) pre[i] = now[i] = next[i] = -1;
        for(i = 1; i <= n; i++) {
            pre[i] = now[g[i]];
            next[now[g[i]]] = i;
            now[g[i]] = i;
        }
        for(i = 1; i <= n; i++) now[i] = cnt[i] = fi[i] = 0;
        int ans = 1;
        for(i = 1; i <= n; i++) {
            if(pre[i] == -1) {
                fi[g[i]] = i;
                now[g[i]] = 0;
                cnt[g[i]] = 1;
            }
            else {
                int need = i - pre[i] - 1;
                if(need + now[g[i]] <= k) {
                    cnt[g[i]]++;
                    now[g[i]] += need;
                }
                else {
//                    cout << "!" << i << ": ";
                    while(fi[g[i]] != i && need + now[g[i]] > k) {
//                        cout << fi[g[i]] << " " << cnt[g[i]] << " " << now[g[i]];
                        j = fi[g[i]];
                        cnt[g[i]]--;
                        now[g[i]] -= next[j] - j - 1;
                        fi[g[i]] = next[j];
                    }
//                    cout << endl;
                    if(fi[g[i]] == i) {
                        cnt[g[i]] = 1;
                        now[g[i]] = 0;
                    }
                    if(need + now[g[i]] <= k) {
                        cnt[g[i]]++;
                        now[g[i]] += need;
                    }
                }
//                cout << "~" << i << " " << cnt[g[i]] << " " << now[g[i]] << endl;
                cmax(ans, cnt[g[i]]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
8 1
1 1 1 2 2 3 2 2
8 2
1 1 2 3 4 1 1 5

*/
