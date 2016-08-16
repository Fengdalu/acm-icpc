#include <iostream>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

#define cmin(x, y) x = min(x, y)
typedef int ft;
const ft inf = 0x3f3f3f;
const int M = 500000+5,N = 20000+5;

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

int n, m, L;
int p[300];
int c[300], t[300];
int f[300][300], cnt[300], fr[300], w[300];
int Y[300];

int check(int T) {
    int op = 0, ed = 1;
    g.init(op, ed, n + m + 10);
    int sum = 0;
    for(int i = 0; i < m; i++) {
        int tot = cnt[i];
        bool flag = true;
        for(int j = 0; j < tot; j++) if(flag)if(t[f[i][j]] > T) flag = false;
        if(!flag) continue;
        g.add(op, i + 2 + n, w[i]);
        sum += w[i];
        for(int j = 0; j < tot; j++)
            g.add(i + 2 + n, f[i][j] + 2, inf);
    }
    for(int i = 0; i < n; i++) g.add(i + 2, ed, c[i]);
    return sum - g.sap();
}

int main() {
    int _T; scanf("%d", &_T);
    int cas = 1;
    while(_T--) {
        scanf("%d%d%d", &n, &m, &L);
        for(int i = 0; i < n; i++) scanf("%d%d", &c[i], &t[i]);
        for(int i = 0; i < n; i++)  Y[i] = t[i];
        sort(Y, Y + n);
        int NY = unique(Y, Y + n) - Y;
        for(int i = 0; i < m; i++) {
            scanf("%d%d", &w[i], &cnt[i]);
            for(int j = 0; j < cnt[i]; j++) {
                scanf("%d", &f[i][j]);
            }
            for(int j = 0; j < cnt[i]; j++) f[i][j]--;
        }
        int l = 0, r = NY - 1;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(check(Y[mid]) >= L) r = mid;
            else l = mid + 1;
        }
        int v = check(Y[l]);
        printf("Case #%d: ", cas++);
        if(v >= L) printf("%d %d\n", Y[l], v);
        else printf("impossible\n");
    }
    return 0;
}
