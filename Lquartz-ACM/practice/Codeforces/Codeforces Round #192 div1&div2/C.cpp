//#include <bits/stdc++.h>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define SZ size()
#define AA first
#define BB second
#define BG begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)

#define NAME ""

#define Maxn 311
char str[Maxn][Maxn];
int row[Maxn], col[Maxn];
vector<PII> g;
int used[Maxn][Maxn];
int visit[Maxn];
int mx[Maxn], my[Maxn];
int n;
struct node {
    int u, v, next;
}e[Maxn * Maxn];
int tot, last[Maxn];

void adde(int u, int v) {
    e[tot].u = u; e[tot].v = v; e[tot].next = last[u]; last[u] = tot++;
}

int check() {
    int i, j, k;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            int flag = 0;
            for(k = 1; k <= n; k++) {
                if(str[i][k] == '.') flag = 1;
                if(str[k][j] == '.') flag = 1;
            }
            if(flag == 0) return -1;
        }
    }
    return 1;
}

int main() {
    int i, j, k, u, v, w;

    //freopen(NAME".in", "r", stdin);
    //freopen(NAME".out", "w", stdout);

    while(scanf("%d", &n) != EOF) {
        for(i = 1; i <= n; i++) {
            scanf("%s", str[i] + 1);
        }
        memset(used, 0, sizeof(used));
        g.clear();
        int ans = check();

        if(ans != -1) {
            int cnt = 0;
            for(i = 1; i <= n; i++) {
                for(j = 1; j <= n; j++) {
                    if(str[i][j] == '.') {
                        cnt++;
                        break;
                    }
                }
            }
            if(cnt == n) {
                for(i = 1; i <= n; i++) {
                    for(j = 1; j <= n; j++) {
                        if(str[i][j] == '.') {
                            g.PB(MP(i, j));
                            break;
                        }
                    }
                }
            }
            else {
                for(j = 1; j <= n; j++) {
                    for(i = 1; i <= n; i++) {
                        if(str[i][j] == '.') {
                            g.PB(MP(i, j));
                            break;
                        }
                    }
                }
            }
            for(i = 0; i < g.SZ; i++) {
                printf("%d %d\n", g[i].AA, g[i].BB);
            }
        }
        else {
            printf("%d\n", ans);
        }
    }

    return 0;
}
