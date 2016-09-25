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
#define Maxn 31111
#define Maxm 111111
struct node {
    int u, v, next;
}e[Maxm];
int tot, last[Maxn];
int indeg[Maxn];
void adde(int u, int v) {
    e[tot].u = u; e[tot].v = v; e[tot].next = last[u]; last[u] = tot++;
}
priority_queue<int> que;
vector<int> ans;
int n, m;
int main() {
    int i, j, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int te;
    scanf("%d", &te);
    for(int ca = 1; ca <= te; ca++) {
        scanf("%d%d", &n, &m);
        tot = 0;
        for(i = 1; i <= n; i++) {
            last[i] = -1;
            indeg[i] = 0;
        }
        for(i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            adde(v, u);
            indeg[u]++;
        }
        while(!que.empty()) que.pop();
        for(i = 1; i <= n; i++) {
            if(indeg[i] == 0) que.push(i);
        }
        ans.clear();
        while(!que.empty()) {
            u =que.top(); que.pop();
            ans.PB(u);
            for(j = last[u]; j != -1; j = e[j].next) {
                v = e[j].v;
                indeg[v]--;
                if(indeg[v] == 0) {
                    que.push(v);
                }
            }
        }
        reverse(ans.BG, ans.ED);
        for(i = 0; i < ans.SZ; i++) {
            if(i) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
