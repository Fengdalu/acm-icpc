#include <bits/stdc++.h>
#define cmin(x, y) x = std::min(x, y)
typedef int ft;
const ft inf = 1e9;
const int M = 500000+5,N = 20000+5;

int n, m;
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
} g;

int x[2*N], y[2*N], c[2*N];
double sqr(double x) { return x * x; }
double dis(double a, double b, double x, double y) {
    return sqrt(sqr(a - x) + sqr(b - y));
}

int up;
int check1(int u, double L) {
    g.init(0, n + m + 1, n + m + 2);
    for(int i = 1; i <= n; i++)
        g.add(0, i, c[i]);
    for(int i = 1; i <= n; i++)
        for(int j = n + 1; j <= n + m; j++) {
            double d = dis(x[i], y[i], x[j], y[j]);
            if(d <= L) {
                g.add(i, j, inf);
            }
        }
    for(int i = n + 1; i <= n + m; i++)
        g.add(i, n + m + 1, u);
    return g.sap() == up;
}

double check(double x) {
    int l = 1, r = up + 1;
    while(l < r) {
        int mid = (l + r) / 2;
        if(check1(mid, x)) r = mid;
        else l = mid + 1;
    }
    return l * sqrt(x);
}

int main() {
    while(true) {
        scanf("%d%d", &n, &m);
        if(n == 0 && m == 0) break;
        up = 0;
        for(int i = 1; i <= n; i++) scanf("%d%d%d", x + i, y + i, c + i);
        for(int i = 1; i <= n; i++) up += c[i];
        for(int i = n + 1; i <= n + m; i++) scanf("%d%d", x + i,  y + i);

        double l = -1, r = -1;
        for(int i = 1; i <= n; i++) {
            double d = dis(x[i], y[i], x[n + 1], y[n + 1]);
            for(int j = n + 1; j <= n + m; j++) {
                d = std::min(d, dis(x[i], y[i], x[j], y[j]));
            }
            l = std::max(l, d);
        }
        for(int i = 1; i <= n; i++)
            for(int j = n + 1; j <= n + m; j++)
                r = std::max(r, dis(x[i], y[i], x[j], y[j]));

        r = 4e4;
        for(int i = 0; i < 60; i++) {
            double mid = (l + r) / 2.0;
            double midmid =  (l + mid) / 2.0;
            double vmm = check(midmid), vm = check(mid);
            if(vmm > vm) l = midmid;
            else r = mid;
        }
        printf("%.0f\n", check(l));
    }
    return 0;
}

