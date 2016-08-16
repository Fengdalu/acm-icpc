#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<fstream>
#include<numeric>
#include<iomanip>
#include<bitset>
#include<list>
#include<stdexcept>
#include<functional>
#include<utility>
#include<ctime>
#include<cassert>
using namespace std;
#define RI(X) scanf("%d", &(X))
#define DRI(X) int (X); scanf("%d", &X)
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
LL modPow(LL a,LL b,LL MOD){
    LL ret=1;for(;b;b>>=1){
        if(b&1)ret=ret*a%MOD;a=a*a%MOD;
    }return ret;
}

const int MXN = 100005;
int pay[205];
int t[205];
int pro[205];
bool s[205][205];
bool now[205];
typedef int ft;
const ft inf = 0x20202020;
const int M = 500000+5,N = 20000+5;
namespace SAP{
    int y[M],nxt[M],gap[N],fst[N],c[N],pre[N],q[N],dis[N];
    ft f[M];
    int S,T,tot,Tn;
    void init(int s,int t,int tn){
        tot=1;
        memset(fst,0,tn*sizeof(int));
        memset(dis,0,tn*sizeof(int));
        S=s;T=t;Tn=tn;
    }
    void add(int u,int v,ft c1,ft c2=0){
        tot++;y[tot]=v;f[tot]=c1;nxt[tot]=fst[u];fst[u]=tot;
        tot++;y[tot]=u;f[tot]=c2;nxt[tot]=fst[v];fst[v]=tot;
    }
    ft sap(){
        int u=S,t=1;ft flow=0;
        rep(i,0,t){
            int u=q[i];
            for(int j=fst[u];j;j=nxt[j])
                if(dis[y[j]]>dis[u]+1&&f[j^1])
                    q[t++]=y[j],dis[y[j]]=dis[u]+1;
        }
        rep(i,0,Tn)gap[dis[i]]++;
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
};
int play(int z,int n,int m){
    memset(now,0,sizeof now);
    VI le,re;
    rep(i,0,n)if(t[i]<=z){
        now[i]=1;
        le.PB(i);
    }
    rep(i,0,m){
        int fail=0;
        rep(j,0,n)
            if(s[i][j]&&!now[i])fail=1;
        if(!fail)re.PB(i);
    }
    int V=sz(le)+sz(re);
    int S=V++;
    int T=V++;
    SAP::init(S,T,V);
    rep(i,0,sz(re))rep(j,0,sz(le))
        if(s[re[i]][le[j]]){
            SAP::add(i,j+sz(re),pay[re[i]]);
        }
    rep(i,0,sz(re))
        SAP::add(S,i,pay[re[i]]);
    int ans=0;
    rep(j,0,sz(le)){
        SAP::add(j+sz(re),T,pro[le[j]]);
        ans+=pro[le[j]];
    }
    ans-=SAP::sap();
    return ans;
}
void solve(){
    int n,m,l;
    RI(n);RI(m);RI(l);
    rep(i,0,n){RI(pay[i]);RI(t[i]);}
    rep(i,0,m){
        RI(pro[i]);
        memset(s[i],0,sizeof s[i]);
        DRI(k);
        while(k--){
            DRI(z);
            s[i][z-1]=1;;
        }
    }
    VI L(t,t+n);
    sort(all(L));
    L.erase(unique(all(L)),L.ED);
    if(play(L[L.SZ-1],n,m)<l){
        printf("impossible\n");
        return;
    }
    int left=0,right=sz(L)-1,good=-1;
    while(right-left>=0){
        int mid=(left+right)/2;
        if(right-left<=1){
            if(play(L[left],n,m)>=l)good=L[left];
            else good=L[right];
            break;
        }
        if(play(L[mid],n,m)>=l)right=mid;
        else left=mid;
    }
    printf("%d %d\n",good,play(good,n,m));
}

int main(){
    int _T=1;
    scanf("%d",&_T);
    rep(CA,0,_T){
        printf("Case #%d: ",CA+1);
        solve();
    }
    return 0;
}
