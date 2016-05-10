#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cassert>
#include <iostream>
using namespace std;

const int maxn = 100010;
int in[maxn];
int c[maxn];
int f[maxn], sum[maxn];
bool chk[maxn];
vector<int>g[maxn];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        in[y]++; in[x]++;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        if(!c[i]) {
            cnt++;
            queue<int>q;
            q.push(i);
            while(q.size()) {
                int x = q.front();
                c[x] = cnt;
                q.pop();
                for(int i = 0; i < g[x].size(); i++) {
                    int v = g[x][i];
                    if(!c[v]) { c[v] = cnt; q.push(v); }
                }
            }
        }

    for(int i = 1; i <= n; i++)
        f[c[i]] += g[i].size();
    for(int i = 1; i <= n; i++)
        sum[c[i]]++;

    for(int i = 1; i <= n; i++) if(g[i].size() <= 1) chk[c[i]] = true;
    int ans = 0;
    for(int i = 1; i <= cnt; i++)
        if(f[i] / 2 == sum[i] - 1) {
             if(chk[i]) ans++;
        }
    cout << ans << endl;
}
