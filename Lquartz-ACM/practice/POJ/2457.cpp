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
#define Maxn 1111
#define Maxm 51111
struct node {
    int u, v, l, next;
}e[Maxm];
int tot, last[Maxn];
int n, m;
int dist[Maxn], pre[Maxn];
queue<int> Q;
void adde(int u, int v, int l) {
    e[tot].u = u; e[tot].v = v;e[tot].l = l; e[tot].next = last[u]; last[u] = tot++;
}
void spfa(int s) {
    int i, j, u, v;
    for(i = 1; i <= n; i++) dist[i] = MOD, pre[i] = -1;
    dist[s] = 0;
    while(!Q.empty()) Q.pop();
    Q.push(s);
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        for(j = last[u]; j != -1; j = e[j].next) {
            v = e[j].v;
            if(dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                pre[v] = u;
                Q.push(v);
            }
        }
    }
}
vector<int> ans;
int main() {
    int i, j, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d%d", &m, &n);
    for(i = 1; i <= n; i++) last[i] = -1;
    tot = 0;
    for(i = 1; i <= m; i++) {
        scanf("%d%d", &u, &v);
        adde(u, v, 1);
    }
    spfa(1);
    if(dist[n] == MOD) printf("-1\n");
    else {
        ans.clear();
        for(i = n; i != -1; i = pre[i]) {
            ans.PB(i);
        }
        reverse(ans.BG, ans.ED);
        printf("%d\n", ans.SZ);
        for(i = 0; i < ans.SZ; i++) printf("%d\n", ans[i]);
    }
    return 0;
}

