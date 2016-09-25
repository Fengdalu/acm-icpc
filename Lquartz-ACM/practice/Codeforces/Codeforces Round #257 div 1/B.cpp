//#pragma comment(linker,"/STACK:102400000,102400000")​

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
typedef pair<long, long> PLL;

#define PB push_back
#define PF push_front
#define PPB pop_back
#define PPF pop_front
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)
#define SORT(g) sort(g.BG, g.ED)
#define MEM(a,b) memset(a,b,sizeof(a))
#define REVERSE(g) reverse(g.BG,g.ED)
#define REVERSE(g,l,r) reverse(g, g.BG + i, g.ED + i)
#define SBUSTR(S,l,r) S.substr(l, (r)-(l))

typedef vector<int> VI;
typedef vector<PII> VII;
typedef deque<int> QI;
typedef deque<PII> QII;
typedef vector<LL> VL;
typedef vector<PLL> VLL;
typedef deque<LL> QL;
typedef deque<PLL> QLL;
typedef vector<string> VS;
typedef deque<string> QS;

const double eps = 1e-8;
const LL MOD = (1LL<<60);
#define Maxn 111111
#define Maxm 811111
struct node {
    int u, v, lab, next;
    LL l;
}e[Maxm];
int tot, last[Maxn];
int n, m, k;
int s[Maxn], gao[Maxn];
LL dist1[Maxn], y[Maxn];

void adde(int u, int v, LL l, int lab) {
    e[tot].u = u; e[tot].v = v; e[tot].l = l; e[tot].lab = lab; e[tot].next = last[u]; last[u] = tot++;
    e[tot].u = v; e[tot].v = u; e[tot].l = l; e[tot].lab = lab; e[tot].next = last[v]; last[v] = tot++;
}
//queue<int> Q;
//priority_queue<pair<LL, int> > Q;
//deque<int> Q;
int que[Maxm], head, tail;
int visit[Maxn];
void spfa(LL* dist) {
    int i, j, u, v;
    for(i = 1; i <= n; i++) {
        dist[i] = MOD;
        visit[i] = false;
    }
    dist[1] = 0;
    visit[1] = true;
    head = tail = 0;
    que[tail++] = 1;
    while(head != tail) {
        u = que[head++];
        if(head == Maxm) head %= Maxm;
        visit[u] = false;
        for(j = last[u]; j != -1; j = e[j].next) {
            v = e[j].v;
            LL tp = dist1[u] + e[j].l;
            if(dist[v] > tp) {
                dist[v] = tp;
                if(!visit[v]) {
                    visit[v] = true;
                    que[tail++] = v;
                    if(tail == Maxm) tail %= Maxm;
                }
            }
        }
    }
}

int check() {
    int i, j, u, v;
    int ret = 0;
    for(i = 1; i <= n; i++) {
        gao[i] = 0;
    }
    for(i = 0; i < 2*m; i++) {
        u = e[i].u; v = e[i].v;
        if(dist1[u] + e[i].l == dist1[v]) {
            gao[v] = 1;
        }
    }
    for(i = 0; i < k; i++) {
        v = s[i];
        if(dist1[v] < y[i]) ret++;
        else if(dist1[v] == y[i]) {
            if(!gao[v]) gao[v] = 1;
            else ret++;
        }
    }
    return ret;
}

int main() {
    int i, j;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int u, v, w;
    while(scanf("%d%d%d", &n, &m, &k) != EOF) {
        tot = 0;
        for(i = 1; i <= n; i++) last[i] = -1;
        for(i = 0; i < m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            adde(u, v, w, 0);
        }
        for(i = 0; i < k; i++) {
            scanf("%d%d", &v, &w);
            s[i] = v; y[i] = w;
            adde(1, v, w, 1);
        }
        spfa(dist1);
        printf("%d\n", check());
    }
    return 0;
}


/*
5  4 2
1 2 100
2 3 1
3 4 1
4 5 1
2 1
3 2

*/
