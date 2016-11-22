/*
* dijkstra 费用流
*/
#include <bits/stdc++.h>
typedef long long LL;
typedef std::pair<int, int> PII;
#define MP(x, y) std::make_pair(x, y)
#define COST_INF 1e9
#define AA first
#define BB second
#define SZ size()
#define PB(x) push_back(x)
#define cmin(x, y) x = std::min(x, y)
template <typename T> class MinCostFlow{
    public:
    struct edge{int to;LL cap;T cost;int rev;};

    int V;
    std::vector<std::vector<edge> >adj;
    std::vector<T>pot;

    std::pair<LL,T>dijkstra(int s,int t,LL FLOW_BOUND){
        std::vector<int>used(V,0);
        std::vector<T>dist(V,COST_INF);
        std::vector<PII>path(V,MP(-1,-1));
        std::priority_queue<std::pair<T,int> >Q;
        dist[s]=0;
        Q.push(MP(0,s));
        while(!Q.empty()){
            int x=Q.top().BB;
            Q.pop();
            if(used[x])continue;
            used[x]=1;
            for(int i=0;i<adj[x].SZ;i++)if(adj[x][i].cap>0){
                edge e=adj[x][i];
                int y=e.to;
                T d=dist[x]+e.cost+pot[x]-pot[y];
                if(d<dist[y]&&!used[y]){
                    dist[y]=d;
                    path[y]=MP(x,i);
                    Q.push(MP(-d,y));
                }
            }
        }
        for(int i=0;i<V;i++)
            pot[i]+=dist[i];
        if(dist[t]==COST_INF)
            return MP(0,0);
        LL f=FLOW_BOUND;
        T sum=0;
        int x=t;
        while(x!=s){
            int y=path[x].AA;
            int id=path[x].BB;
            sum+=adj[y][id].cost;
            cmin(f,adj[y][id].cap);
            x=y;
        }
        x=t;
        while(x!=s){
            int y=path[x].AA;
            int id=path[x].BB;
            adj[y][id].cap-=f;
            int id2=adj[y][id].rev;
            adj[x][id2].cap+=f;
            x=y;
        }
        return MP(f,f*sum);
    }
    public:
    MinCostFlow(int n){//[0,n)
        V=n;
        adj.resize(V,std::vector<edge>(0));
        pot.resize(V,0);
    }
    void add_edge(int s,int t,LL f,T c){
        edge e1={t,f,c,(int)adj[t].SZ};
        edge e2={s,0LL,-c,(int)adj[s].SZ};
        adj[s].PB(e1);
        adj[t].PB(e2);
    }
    std::pair<LL,T>mincostflow(int s,int t,LL FLOW_BOUND=(1LL<<48)){
        std::pair<LL,T>ans=MP(0LL,0);
        while(FLOW_BOUND>0){
            std::pair<LL,T>tmp=dijkstra(s,t,FLOW_BOUND);
            if(tmp.AA==0)break;
            ans.AA+=tmp.AA;
            ans.BB+=tmp.BB;
            FLOW_BOUND-=tmp.AA;
        }
        return ans;
    }
};

const int N = 4e3;
int a[N], b[N];
int main() {
    int n, p, s;
    scanf("%d%d%d", &n, &p, &s);
    MinCostFlow<LL> G(n + 10);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    for(int i = 1; i <= n; i++) scanf("%d", b + i);
    LL MX = 1e9;
    int op = 0;
    int pn = n + 1, ps = n + 2, ed = n + 3;
    for(int i = 1; i <= n; i++) G.add_edge(op, i, 1, 0);
    for(int i = 1; i <= n; i++) G.add_edge(i, pn, 1, MX - a[i]);
    for(int i = 1; i <= n; i++) G.add_edge(i, ps, 1, MX - b[i]);
    G.add_edge(pn, ed, p, 0);
    G.add_edge(ps, ed, s, 0);
    printf("%I64d\n", MX*(p+s) - G.mincostflow(op, ed).second);

    for(int i = 1; i <= n; i++) {
        int sz = G.adj[i].size();
        for(int j = 0; j < sz; j++)
            if(G.adj[i][j].to == pn && G.adj[i][j].cap == 0)
                printf("%d ", i);
    }
    puts("");
    for(int i = 1; i <= n; i++) {
        int sz = G.adj[i].size();
        for(int j = 0; j < sz; j++)
            if(G.adj[i][j].to == ps && G.adj[i][j].cap == 0)
                printf("%d ", i);
    }
    return 0;
}
