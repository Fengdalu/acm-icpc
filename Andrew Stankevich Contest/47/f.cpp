#include <bits/stdc++.h>
using namespace std;

set<int>g[1001];
set<int>d[5];
set<int>col[1001];
int c[1001];
int main() {
    int n;
    scanf("%d", &n);
    memset(c, -1, sizeof c);
    for(int i = 0; i < n - 1; i++) {
        int x, y; scanf("%d%d", &x, &y);
        g[x].insert(y);
        g[y].insert(x);
    }
    for(int i = 1; i <= n; i++) if(g[i].size() >= 4) {
        d[4].insert(i);
    }
    int x, y;
    while(true) {
        int op = -1, t;
        for(int i = 1; i <= 4; i++) if(op == -1) {
            for(auto x: d[i]) if(c[x] == -1) if(op == -1) {
                for(int j = 0; j < 4; j++) {
                    c[x] = j;
                    bool flag = true;
                    for(auto y: g[x]) if(col[y].size() == 3) flag = false;
                    if(flag) {
                        op = x; t = j;
                        break;
                    }
                    c[x] = -1;
                }
            }
        }
        if(op == -1) {
            for(int i = 1; i <= n; i++) if(c[i] == -1) {
                for(int j = 0; j < 4; j++) {
                    bool flag = true;
                    for(auto y: g[i]) {
                        if(c[i] == c[y]) flag = false;
                    }
                    if(flag) {
                        op = i; t = j;
                    }
                }
            }
        }
        c[op] = t + 1;
        for(int i = 1; i <= 4; i++)  {
            if(d[i].find(op) != d[i].end()) d[i].erase(d[i].find(op));
        }

        for(auto &y: g[op]) {
            g[y].erase(g[y].find(op));
            auto &dd = d[4 - col[y].size()];
            if(dd.find(y) != dd.end()) dd.erase(dd.find(y));
            col[y].insert(t);
            d[4 - col[y].size()].insert(y);
        }
        printf("%d %d\n", op, t + 1);
        fflush(stdout);
        scanf("%d%d", &x, &y);
        if(x == -1 && y == -1) break;
        c[x] = y;
    }
    return 0;
}
