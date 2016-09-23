#include <bits/stdc++.h>

const int N = 105;
int n,m;
int a[N][N];
int d[N][N];
char str[N];
const int inf = N * N;
int vis[N][N];
int st[N][N];
int ed[N][N];
int mf[N][N];
inline int hefa(int x, int y)
{
    if (x < 1 || x > n) return 0;
    if (y < 1 || y > m) return 0;
    return 1;
}
char ch[4];
int gao(int x ,int y)
{
    if(!hefa(x,y))
        return inf;
    if(vis[x][y])
        return ed[x][y];
    vis[x][y] = 1;
    int nx = x;
    int ny = y;
        if (d[nx][ny] == 0) nx -= a[nx][ny];
        else if (d[nx][ny] == 1) ny += a[nx][ny];
        else if (d[nx][ny] == 2) nx += a[nx][ny];
        else if (d[nx][ny] == 3) ny -= a[nx][ny];
    ed[x][y] = std::min(ed[x][y], gao(nx,ny) + 1);
    return ed[x][y];
}
void run()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(i == n && j == m) break;
            scanf("%s", str);
            int l = strlen(str);
            if(str[l - 1] == 'N') d[i][j] = 0;
            if(str[l - 1] == 'E') d[i][j] = 1;
            if(str[l - 1] == 'S') d[i][j] = 2;
            if(str[l - 1] == 'W') d[i][j] = 3;
            a[i][j] = str[0] - '0';
            for(int p = 1; p < l - 1; p++)
                a[i][j] = a[i][j] * 10 + str[p] - '0';
        }
    }
    a[n][m] = 999;
    d[n][m] = 1;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++)
    {
        st[i][j] = inf;
        ed[i][j] = inf;
    }
    st[1][1] = 0;
    ed[n][m] = 0;

    // bfs st
    memset(vis, 0, sizeof vis);
    int nx = 1; int ny = 1; int nl = 0;
    while(hefa(nx,ny) && !vis[nx][ny])
    {
        vis[nx][ny] = 1;
        st[nx][ny] = nl;
        nl++;
        if (d[nx][ny] == 0) nx -= a[nx][ny];
        else if (d[nx][ny] == 1) ny += a[nx][ny];
        else if (d[nx][ny] == 2) nx += a[nx][ny];
        else if (d[nx][ny] == 3) ny -= a[nx][ny];
    }

    //bfs ed

    memset(vis, 0, sizeof vis);
    vis[n][m] = 1;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++)
    {
        if(vis[i][j]) continue;
        gao(i,j);
    }
    int noneans = ed[1][1];
    int ans = inf;
    int ansx = 0;
    int ansy = 0;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) mf[i][j] = inf;
    for(int i = 1;i <= n; i++)
    {
        int mini = inf;
        for(int j = 1; j <= m; j++)
            mini = std::min(mini, ed[i][j]);
        for(int j = 1; j <= m; j++)
            mf[i][j] = std::min(mf[i][j], mini);
    }
    for(int j = 1; j <= m; j++)
    {
        int mini = inf;
        for(int i = 1; i <= n; i++)
            mini = std::min(mini, ed[i][j]);
        for(int i = 1; i <= n; i++)
            mf[i][j] = std::min(mf[i][j], mini);
    }
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++)
    {
        if(st[i][j] + mf[i][j] + 1< ans)
        {
            ans = st[i][j] + mf[i][j] + 1;
            ansx = i;
            ansy = j;
        }
    }
    /*
    puts("");
    puts("st");
    for(int i = 1; i <= n; i++) {for(int j = 1; j <= m; j++) printf("%d ", st[i][j]); puts("");}
    puts("ed");
    for(int i = 1; i <= n; i++) {for(int j = 1; j <= m; j++) printf("%d ", ed[i][j]); puts("");}
    puts("mf");
    for(int i = 1; i <= n; i++) {for(int j = 1; j <= m; j++) printf("%d ", mf[i][j]); puts("");}
    printf("ans = %d\n", ans);
    printf("ansx = %d\n", ansx);
    printf("ansy = %d\n", ansy);
    */
    if(noneans == inf && ans == inf)
    {
        puts("impossible");
        return;
    }
    if(ans >= noneans)
    {
        printf("none %d\n", noneans);
        return;
    }
    if(ans < noneans)
    {
        int mina = inf;
        int mind = 0;
        int x,y;
        for(int i = 1; i <= n; i++) if(i != ansx)
        {
            x = i;
            y = ansy;
            int nowd;
            if(ed[x][y] == mf[ansx][ansy])
            {
                if(i < ansx) nowd = 0; else nowd = 2;
                if(mina == std::abs(ansx - i) && ch[mind] > ch[nowd])
                {
                    mind = nowd;
                }
                if(mina > std::abs(ansx - i))
                {
                    mina = std::abs(ansx - i);
                    mind = nowd;
                }
            }
        }
        for(int j = 1; j <= m; j++) if(j != ansy)
        {
            x = ansx;
            y = j;
            int nowd;
            if(ed[x][y] == mf[ansx][ansy])
            {
                if(j < ansy) nowd = 3; else nowd = 1;
                if(mina == std::abs(ansy - j) && ch[mind] > ch[nowd])
                {
                    mind = nowd;
                }
                if(mina > std::abs(ansy - j))
                {
                    mina = std::abs(ansy - j);
                    mind = nowd;
                }
            }
        }
        //printf("mind = %d\n", mind);
        printf("%d %d %d%c %d\n", ansx - 1, ansy - 1, mina, ch[mind], ans);
    }
}
int main()
{
    ch[0] = 'N';
    ch[1] = 'E';
    ch[2] = 'S';
    ch[3] = 'W';
    int cas = 1;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n == 0 && m == 0) return 0;
        printf("Case %d: ", cas++);
        run();
    }
}
