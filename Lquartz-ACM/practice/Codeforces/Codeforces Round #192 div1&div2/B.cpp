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

int used[Maxn];
int n, m;
vector<PII> g;

int main() {
    int i, j, k, u, v, w;

    //freopen(NAME".in", "r", stdin);
    //freopen(NAME".out", "w", stdout);
    while(cin >> n >> m) {
        for(i = 1; i <= n; i++) used[i] = 0;
        for(i = 0; i < m; i++) {
            cin >> u >> v;
            used[u] = used[v] = 1;
        }
        for(i = 1; i <= n; i++) {
            if(!used[i] ) {
                w = i;
                break;
            }
        }
        g.clear();
        for(i = 1; i <= n; i++) {
            if(i == w) continue;
            g.PB(MP(i, w));
        }
        printf("%d\n", (int)g.SZ);
        for(i = 0; i < g.SZ; i++) printf("%d %d\n", g[i].AA, g[i].BB);
    }

    return 0;
}
