#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

vector<int>g[100100];
int tot = 0;
int ans;
void dfs(int x, int rt, int fa) {
    int nc = 0;
    for(auto &t: g[x])  if(t != fa) {
        dfs(t, rt, x);
        nc++;
    }
    if(rt == x && nc == 1) tot++;
    else if(nc == 0) tot++;
}
int main() {
    int _T, n;
    scanf("%d", &_T);
    while(_T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) g[i].clear();
        for(int i = 0; i < n - 1; i++) {
            int x, y; scanf("%d%d", &x, &y); x--; y--;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        int tot = 0;
        for(int i = 0; i < n; i++)
        if(g[i].size() & 1) tot++;
        cout << n - 1 + (tot - 1) / 2 << endl;
    }
    return 0;
}
