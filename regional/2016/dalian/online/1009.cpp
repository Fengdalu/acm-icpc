#include <stdio.h>
#include <algorithm>
#include <queue>

const int MAXN = 200005;
int n,m;
std::pair<int,int> e[MAXN];
int tot;
int h[MAXN];
inline void adde(int u,int v)
{
    e[tot].first = u;
    e[tot].second = v;
    tot++;
}
int S;
int nxt[MAXN];
int val[MAXN];
int bef[MAXN];
int l;
int ans[MAXN];
void add(int x)
{
    val[l] = x;
    nxt[l - 1] = l;
    bef[l] = l - 1;
    l++;
}
void del(int i)
{
    nxt[bef[i]] = nxt[i];
    bef[nxt[i]] = bef[i];
}
void run()
{
    tot = 0;
    scanf("%d%d",&n,&m);
    for(int i = 0,u,v; i < m; i++)
        scanf("%d%d",&u,&v), adde(u,v), adde(v,u);
    sort(e, e + tot);
    for(int i = 1; i <= n; i++) h[i] = -1;
    for(int i = 0; i < tot; i++) if(h[e[i].first] == -1) h[e[i].first] = i;
    for(int i = 1; i <= n; i++) if(h[i] == -1) h[i] = tot + 10;
    scanf("%d",&S);
    std::queue<std::pair<int, int> >Q;
    Q.push(std::make_pair(S, 0));
    std::pair<int,int> p;
    int s;
    int d;
    int now;
    l = 1;
    nxt[0] = -1;
    for(int i = 1; i <= n; i++) if(i != S) add(i);
    nxt[l - 1] = -1;
    int pi = 0;
    for(int i = 1; i <= n; i++) ans[i] = -1;
    while(!Q.empty())
    {
        s = Q.front().first;
        d = Q.front().second;
        Q.pop();
        now = h[s];
        int i = 0;
        while(~nxt[i])
        {
            i = nxt[i];
            while(now < tot && e[now].first == s && e[now].second < val[i]) now++;
            if(now < tot && e[now].first == s && e[now].second == val[i]) {continue;}
            ans[val[i]] = d + 1;
            Q.push(std::make_pair(val[i], d + 1));
            del(i);
        }
    }
    //puts("ANS\nANS\n");
    int flag = 0;
    for(int i = 1; i <= n; i++) if(i != S)
    {
        if(flag) printf(" "); else flag = 1;
        printf("%d", ans[i]);
    }
    puts("");
}
int main()
{
    int n,m;
    int T; scanf("%d",&T);
    while(T--) {run();}
    return 0;
}
