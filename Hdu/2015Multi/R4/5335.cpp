nclude <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define PII pair<int, int>
#define MP(x, y) make_pair(x, y)
#define MAXN 1010
#define X first
#define Y second
#define SQR(x) ((x) * (x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) y = min(x, y)

template<class T> struct queue
{
    int l, r;
    T buf[SQR(MAXN)];
    queue() { l = 0; r = -1; }
    void add(T x){
        buf[++r] = x;
    }
    T& top(){
        return buf[l];
    }
    T& pop(){
        return buf[l++];
    }
    void reset(){
        l = 0; r = -1;
    }
    int size(){
        return r - l + 1;
    }
};

queue<PII>q1, q2, q3;
int n, m;
char buf[MAXN];
bool c[MAXN][MAXN];
bool vis[MAXN][MAXN];
PII pre[MAXN][MAXN];

const PII VEC[4] = { MP(0, 1), MP(1, 0), MP(0, -1), MP(-1, 0)  };

void bfs1(){
    memset(vis, 0, sizeof vis);
    for(int i = 0; i <= n; i++) vis[i][0] = true; for(int i = 0; i <= m; i++) vis[0][i] = true;
    for(int i = 0; i <= n; i++) vis[i][m + 1] = true; for(int i = 0; i <= m; i++) vis[n + 1][i] = true;

    q1.reset();
    q2.reset();
    if(c[1][1] == 0) q1.add(MP(1, 1)); else return;
    vis[1][1] = true;

    int d = 0;
    while(q1.size()){
        PII p = q1.pop();
        cmax(d, p.X + p.Y);
        for(int i = 0; i < 4; i++) {
            if(!vis[p.X + VEC[i].X][p.Y + VEC[i].Y] && !c[p.X + VEC[i].X][p.Y + VEC[i].Y]){
            vis[p.X + VEC[i].X][p.Y + VEC[i].Y] = true;
            q1.add(MP(p.X + VEC[i].X, p.Y + VEC[i].Y));
        }
        }
    }
    q1.l = 0;
    while(q1.size()){
        PII p = q1.pop();
        if(p.X + p.Y == d) { q2.add(p); vis[p.X][p.Y] = true; }
    }
}

void bfs2() {
    memset(pre, -1, sizeof pre);
    while(q2.size()) {
        q3.reset();
        bool flg = false;
        while(!q3.size() || (q2.size() && q3.top().X + q3.top().Y == q2.top().X + q2.top().Y)) {
            if(!c[q2.top().X][q2.top().Y]) flg = true;
            q3.add(q2.pop());
        }
        while(q3.size())  {
            PII p = q3.pop();
            if(c[p.X][p.Y] && flg) continue;
            for(int i = 0; i < 2; i++) if(!vis[p.X + VEC[i].X][p.Y + VEC[i].Y]){
                q2.add(MP(p.X + VEC[i].X, p.Y + VEC[i].Y));
                vis[p.X + VEC[i].X][p.Y + VEC[i].Y] = true;
                pre[p.X + VEC[i].X][p.Y + VEC[i].Y] = p;
            }
        }
    }
}

int ans[MAXN * MAXN];
int main()
{
    //freopen("../data/1009/1009.in", "r", stdin);
    int CASE; scanf("%d", &CASE);
    while(CASE--){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++){
            scanf("%s", &buf);
            for(int j = 1; j <= m; j++) c[i][j] = (buf[j - 1] == '1') ? true : false;
        }
        bfs1();
        if(!q2.size()) q2.add(MP(1, 1));
        bfs2();
        PII p(n, m);
        int cnt = 0;
        while(p != MP(-1, -1)){
            ans[cnt++] = c[p.X][p.Y];
            p = pre[p.X][p.Y];
        }
        reverse(ans, ans + cnt);
        int i = 0;
        for(;i < cnt; i++) if(ans[i] == 1) break;
        if(i == cnt) printf("0");
        for(; i < cnt; i++) printf("%d", ans[i]); printf("\n");
    }
    return 0;
}


