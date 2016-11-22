#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

typedef long long ll;

struct state {
    int a, b, c;
    state(){}
    state(int a, int b, int c): a(a), b(b), c(c) {}
};
vector<state>f[90000];
int c[301][301];
bool vis[301][301];
int n, m, p;
const int inf = 1e9;

const int vx[4] = {-1, 0, 1, 0};
const int vy[4] = {0, 1, 0, -1};
void cmin(int &a, int b) {
    a = min(a, b);
}

int dis(int x, int y, int a, int b) {
    return abs(x - a) + abs(y - b);
}
int main() {
    scanf("%d%d%d", &n, &m, &p);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            int x;
            scanf("%d", &x);
            f[x].push_back(state(i, j, inf));
        }
    f[0].push_back(state(0, 0, 0));
    for(int k = 1; k <= p; k++) {
        if(f[k - 1].size() * f[k].size() >= n * m) {
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++) {
                    c[i][j] = inf;
                    vis[i][j] = 0;
                }

            queue<pair<int, int> >q;
            for(int i = 0; i < f[k - 1].size(); i++) {
                q.push(make_pair(f[k - 1][i].a, f[k - 1][i].b));
                c[f[k - 1][i].a][f[k - 1][i].b] = f[k - 1][i].c;
                vis[f[k - 1][i].a][f[k - 1][i].b] = true;
            }
            while(q.size()) {
                pair<int, int> e = q.front();
                int v = c[e.first][e.second];
                vis[e.first][e.second] = false;
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int x = e.first + vx[i];
                    int y = e.second + vy[i];
                    if(x < 0 || x > n - 1 || y < 0 || y > m - 1) continue;
                    if(v + 1 < c[x][y]) {
                        c[x][y] = v + 1;
                        if(!vis[x][y]) {
                            vis[x][y] = true;
                            q.push(make_pair(x, y));
                        }
                    }
                }
            }
            for(int i = 0; i < f[k].size(); i++) {
                f[k][i].c = c[f[k][i].a][f[k][i].b];
            }
           continue;
        }
        for(int i = 0; i < f[k].size(); i++)
            for(int j = 0; j < f[k - 1].size(); j++)
                cmin(f[k][i].c, f[k - 1][j].c + dis(f[k][i].a, f[k][i].b, f[k - 1][j].a, f[k - 1][j].b));
    }
    int ans = inf;
    for(int i = 0; i < f[p].size(); i++)
        cmin(ans, f[p][i].c);
    cout << ans << endl;
    return 0;
}

