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
#define PF push_front
#define PPB pop_back
#define PPF pop_front
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define OP begin()
#define ED end()
#define SORT(x) sort(x.begin(), x.end())
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)
 
const double eps = 1e-8;
const LL MOD = 1000000007;
const LL INF = 0x3f3f3f3f;
#define Maxn 2111
#define Maxm 11111
struct node {
    int u, v, w;
}e[Maxn];
vector<PII> g[4];
int tot, cur;
int n, m;
int used[Maxn];
int sum[2 * Maxn];
int visit[100][100];
void adde(int u, int v, int w) {
    e[tot].u = u; e[tot].v = v; e[tot].w = w;
    visit[u][v] = visit[v][u] = 1;
    used[w] = 1;
    tot++;
}
int main() {
    int i, j, k, p, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int te;
    scanf("%d", &te);
    for(int ca = 1; ca <= te; ca++) {
        scanf("%d%d", &n, &m);
        for(i = 0; i <= n; i++){
            for(j = 0; j <= n; j++) visit[i][j] = 0;
            visit[i][i] = 1;
        }
        memset(used, 0, sizeof(used));
        memset(sum, 0, sizeof(sum));
        tot = cur = 0;
        cur = n / 3;
        for(j = 2, i = 1; j <= m; j++) {
            if(j % 3 == 1){
                adde(i, i + 1, j);
                sum[i + 1] = sum[i] + j;
                i++;
                if(i == n) break;
            }
        }
        if(i < n) {
            for(j = 3; j <= m; j++) {
                if(used[j]) continue;
                if(j % 3 == 2){
                    adde(i, i + 1, j);
                    sum[i + 1] = sum[i] + j;
                    i++;
                    if(i == n) break;
                }
            }
            if(i < n) {
                for(j = 4; j <= m; j++) {
                    if(used[j]) continue;
                    if(j % 3 == 0){
                        adde(i, i + 1, j);
                        sum[i + 1] = sum[i] + j;
                        i++;
                        if(i == n) break;
                    }
                }
            }
        }
        for(j = 1; j <= m; j++) {
            if(used[j]) continue;
            if((sum[n] + j) % 3 != 0) continue;
            adde(n, 1, j);
            sum[n + 1] = sum[n] + j;
            break;
        }
        for(i = 2; i <= n; i++) {
            sum[n + i] = sum[n + i - 1] + sum[i] - sum[i - 1];
        }
//        for(i = 1; i <= 2 * n; i++)cout << sum[i] << " "; cout << endl;
//        for(i = 1; i <= n; i++) {
//            for(j = 1; j <= n; j++){
//                if(i < j) w = sum[j] - sum[i];
//                else w = sum[j + n] - sum[i];
//                cout << w << " ";
//            }
//            cout << endl;
//        }
        g[0].clear();
        g[1].clear();
        g[2].clear();
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                if(visit[i][j]) continue;
                if(i < j) w = sum[j] - sum[i];
                else w = sum[j + n] - sum[i];
                g[w % 3].PB(MP(i, j));
            }
        }
//        cout << g[0].SZ << " ! " << g[1].SZ << " " << g[2].SZ << endl;
        for(i = 1; i <= m; i++) {
            if(!used[i]) {
                w = i % 3;
                for(j = 0; j < g[w].SZ; j++) {
                    u = g[w][j].AA, v = g[w][j].BB;
                    if(!visit[u][v]) {
                        adde(u, v, i);
                        break;
                    }
                }
            }
        }
//        for(i = 0; i < tot; i++) printf("%d : %d -> %d %d\n", i, e[i].u, e[i].v, e[i].w);
        printf("Case #%d:\n", ca);
        if(tot < m) printf("-1\n");
        else {
            for(i = 0; i < tot; i++) printf("%d %d %d\n", e[i].u, e[i].v, e[i].w);
        }
    }
    return 0;
}

