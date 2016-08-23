#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define cmin(x, y) x = min(x, y)
typedef int ft;
const ft inf = 0x3f3f3f;
const int M = 10000000,N = 100100+5;

struct SAP{
    int y[M],nxt[M],gap[N],fst[N],c[N],pre[N],q[N],dis[N];
    ft f[M];
    int S,T,tot,Tn;
    void init(int s,int t,int tn){
        tot=1;
        memset(fst,0,sizeof (int) * tn);
        memset(dis, 0, sizeof(int) * tn);
        S=s;T=t;Tn=tn;
    }
    void add(int u,int v,ft c1,ft c2=0){
        tot++;y[tot]=v;f[tot]=c1;nxt[tot]=fst[u];fst[u]=tot;
        tot++;y[tot]=u;f[tot]=c2;nxt[tot]=fst[v];fst[v]=tot;
    }
    ft sap(){
        int u=S,t=1;ft flow=0;
        for(int i = 0; i < t; i++){
            int u=q[i];
            for(int j=fst[u];j;j=nxt[j])
                if(dis[y[j]]>dis[u]+1&&f[j^1])
                    q[t++]=y[j],dis[y[j]]=dis[u]+1;
        }
        for(int i = 0; i < Tn; i++)gap[dis[i]]++;
        while(dis[S]<=Tn){
            while(c[u]&&(!f[c[u]]||dis[y[c[u]]]+1!=dis[u]))
                c[u]=nxt[c[u]];
            if(c[u]){
                pre[y[c[u]]]=c[u]^1;
                u=y[c[u]];
                if(u==T){
                    ft minf=inf;
                    for(int p=pre[T];p;p=pre[y[p]])
                        cmin(minf,f[p^1]);
                    for(int p=pre[T];p;p=pre[y[p]])
                        f[p^1]-=minf,f[p]+=minf;
                    flow+=minf;u=S;
                }
            }else {
                if(!(--gap[dis[u]]))break;
                int mind=Tn;
                c[u]=fst[u];
                for(int j=fst[u];j;j=nxt[j])
                    if(f[j]&&dis[y[j]]<mind)
                        mind=dis[y[j]],c[u]=j;
                dis[u]=mind+1;
                gap[dis[u]]++;
                if(u!=S)u=y[pre[u]];
            }
        }
        return flow;
    }
}g;

int a[1000], b[1000];
bool vis[1000];
int n;
const int nn = 100000;
inline int check() {
    int st = 0, ed = nn + n + 5;
    g.init(st, ed, nn + n + 10);
    for(int i = 0; i < n; i++)
        if(vis[i]) {
            int to = i + 1 + nn;
            int l = a[i], r = b[i];
            for(int j = l; j <= r; j++) g.add(to, j, 1);
        }
    for(int i = 0; i < n; i++)
        if(vis[i]) g.add(st, i + 1 + nn, 1);
    g.add(st, ed, 1);
    for(int i = 1; i <= 100000; i++)
        g.add(i, ed, 1);
    return g.sap();
}

inline int run() {
    if(scanf("%d", &n) != 1) return 0;
    for(int i = 0; i < n; i++) scanf("%d%d", &a[i], &b[i]);
    for(int i = 0; i < n; i++) vis[i] = true;
    int ans = check();
    for(int i = 0; i < n; i++) {
        vis[i] = false;
        if(check() != ans) vis[i] = true;
    }
    printf("%d\n", ans);
    bool flag = false;
    for(int i = 0; i < n; i++) if(vis[i])  {
        if(flag) printf(" %d", i + 1);
        else printf("%d", i + 1);
        flag = true;
    }
    printf("\n");
    return 1;
}

int main() {
    int _T; scanf("%d", &_T);
    while(_T--) run();
    return 0;
}

