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

#define Maxn 1011
#define INF 100000000
int n, m;
char g[Maxn][Maxn];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int step[Maxn][Maxn], need[Maxn][Maxn];
int ok[Maxn][Maxn];
queue<PII> que;
int sx, sy, ex, ey;

int main() {
    int i, j, k, u, v, w;

    //freopen(NAME".in", "r", stdin);
    //freopen(NAME".out", "w", stdout);

    while(scanf("%d%d", &n, &m) != EOF) {
        for(i = 1; i <= n; i++) {
            scanf("%s", g[i] + 1);
        }
        for(i = 0; i <= n + 1; i++) {
            for(j = 0; j <= m + 1; j++) {
                ok[i][j] = 0;
            }
        }
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= m; j++) {
                if(g[i][j] == 'T') continue;
                if(g[i][j] == 'S') {
                    sx = i; sy = j;
                }
                if(g[i][j] == 'E') {
                    ex = i; ey = j;
                }
                ok[i][j] = 1;
            }
        }
        while(!que.empty()) que.pop();
        que.push(MP(sx, sy));
        for(i = 0; i <= n + 1; i++) {
            for(j = 0; j <= m + 1; j++) {
                step[i][j] = INF;
                need[i][j] = INF;
            }
        }
        step[sx][sy] = 0;
        while(!que.empty()) {
            u = que.front().AA; v = que.front().BB;
            que.pop();
            for(k = 0; k < 4; k++) {
                i = u + dx[k]; j = v + dy[k];
                if(!ok[i][j]) continue;
                if(step[i][j] == INF) {
                    step[i][j] = step[u][v] + 1;
                    que.push(MP(i, j));
                }
            }
        }
        need[ex][ey] = 0;
        que.push(MP(ex,ey));
        while(!que.empty()) {
            u = que.front().AA; v = que.front().BB;
            que.pop();
            for(k = 0; k < 4; k++) {
                i = u + dx[k]; j = v + dy[k];
                if(!ok[i][j]) continue;
                if(need[i][j] == INF) {
                    need[i][j] = need[u][v] + 1;
                    que.push(MP(i, j));
                }
            }
        }
        int fa = step[ex][ey];
        int ans = 0;
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= m; j++) {
                if('0' <= g[i][j] && g[i][j] <= '9') {
                    if(need[i][j] <= fa) {
                        ans += g[i][j] - '0';
                    }
                }
            }
        }
        printf("%d\n", ans);

    }

    return 0;
}
