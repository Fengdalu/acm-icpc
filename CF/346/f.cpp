#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define mp(x, y) make_pair(x, y)
typedef pair<int, int> pii;

const int maxn = 1010;
int n, m;
long long K;
int c[maxn][maxn];
pair<int, pii>q[maxn * maxn];
int id[maxn][maxn];
int fa[maxn * maxn];
int cc[maxn * maxn];
int ans[maxn][maxn];
bool vis[maxn][maxn];
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
int find(int x) { if(fa[x] == x) return fa[x]; return fa[x] = find(fa[x]); }
int main() {
    cin >> n >> m >> K;
    long long sum(0);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &c[i][j]);
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) q[cnt++] = mp(-c[i][j], mp(i, j));
    sort(q, q + cnt);
    int tot = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            id[i][j] = tot++;

    for(int i = 0; i < tot; i++) cc[i] = 1;
    for(int i = 0; i < tot; i++) fa[i] = i;
    sum = n * m;
    for(int i = 0; i < cnt; i++) {
        long long v = -q[i].first;
        long long target = K / v;
        vector<int>s;
        for(int j = 0; j < 4; j++)  {
            int x = q[i].second.first + dx[j];
            int y = q[i].second.second + dy[j];
            if(x > -1 && x < n && y > -1 && y < m && c[x][y] >= v)
                s.push_back(find(id[x][y]));
        }
        s.push_back(find(id[q[i].second.first][q[i].second.second]));
        sort(s.begin(), s.end());
        s.resize(unique(s.begin(), s.end()) - s.begin());
        long long t = 0;
        for(int i = 0; i < s.size(); i++)
            t += cc[s[i]];
        if(K % v == 0 && t >= target) {
            queue<pair<int, int> >q0;
            q0.push(q[i].second);
            while(q0.size() && target) {
                target--;
                int x = q0.front().first;
                int y = q0.front().second;
                q0.pop();
                ans[x][y] = v;
                vis[x][y] = true;
                for(int i = 0; i < 4; i++) {
                    int a = x + dx[i];
                    int b = y + dy[i];
                    if(a > -1 && b > -1 && a < n && b < m && c[a][b] >= v && !vis[a][b]) {
                        vis[a][b] = true;
                        q0.push(mp(a, b));
                    }
                }
            }
            puts("YES");
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++)
                    printf("%d ", ans[i][j]);
                puts("");
            }
            return 0;
        }
        int root = find(s[0]);
        for(int i = 1; i < s.size(); i++) {
            int t = cc[find(s[i])];
            fa[find(s[i])] = root;
            cc[root] += t;
        }
    }
    puts("NO");
    return 0;
}
