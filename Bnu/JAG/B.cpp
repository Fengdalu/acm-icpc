#include <bits/stdc++.h>

const int N = 300;
int dis[N][N];
char s[N][N];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    memset(dis, -1, sizeof dis);
    for(int i = 0; i < n; i++) scanf("%s", s[i]);
    std::queue<std::pair<int, int> >q;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(s[i][j] == '%') {
                q.push(std::make_pair(i, j));
                dis[i][j] = 0;
            }

    int V[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    while(q.size()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int tx = x + V[i][0];
            int ty = y + V[i][1];
            if(tx < 0 || tx > n - 1 || ty < 0 || ty > m - 1) continue;
            if(dis[tx][ty] != -1) continue;
            if(s[tx][ty] == '#') continue;
            dis[tx][ty] = dis[x][y] + 1;
            q.push(std::make_pair(tx, ty));
        }
    }
    int target = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        if(s[i][j] == '@') target = dis[i][j];

    bool flag = false;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        if(s[i][j] == '$' && dis[i][j] != -1 && dis[i][j] <= target)
            flag = true;
    if(flag) printf("No");
    else printf("Yes");
    return 0;
}

