#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const int N = 1e5+10;
typedef std::pair<int, int> pii;
typedef long long ll;
std::vector<pii> q;
int n;
long long l;
int c[N];
ll pre[N];
int ans = inf;

int cmp(pii a, pii b)
{
    return a.first - a.second > b.first - b.second;
}

void check(std::vector<pii> &q, int mx, int &ans)
{
    if(mx == -1) return;
    int target = l - mx;
    int days = 1;
    long long spider = 0;
    int sz = q.size();
    long long dis = 0;
    if(dis >= target)
    {
        ans = days;
        return;
    }
    for(int i = 0; i < sz; i++)
    {
        if(dis >= target)
        {
            ans = days;
            return;
        }
        spider += c[i];
        dis += q[i].first - q[i].second;
        days++;
        if(spider >= dis) return;
    }
    if(dis >= target)
    {
        ans = days;
        return;
    }
}
long long sumstep[N];
long long sumspid[N];
long long det[N];
long long h[N];
long long dp[100005][20];
int mm[100005];
void init()
{
    mm[0] = -1;
    for(int i = 1; i < 100005; i++)
    {
        if((i & (i - 1)) == 0) mm[i] = mm[i - 1] + 1;
        else mm[i] = mm[i - 1];
    }
    for(int i=0; i<20; i++)
        for(int j=0; j<n; j++)
        {
            if(i==0)
                dp[j][i]=h[j];
            else if(j+(1<<i)-1<n)
            {
                dp[j][i]=min(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);
            }
        }
}
long long query(int l,int r)
{
    if(l>r)return inf;
    int two=mm[r-l+1];
    return min(dp[l][two],dp[r-(1<<two)+1][two]);
}
bool ok[N];
int main()
{
    scanf("%d%lld", &n, &l);
    int mx = -1;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if(b >= a) mx = std::max(mx, a);
        else q.push_back(std::make_pair(a, b));
    }
    for(int i=0; i<n; i++)scanf("%d",&c[i]);
    std::sort(q.begin(), q.end(), cmp);
    check(q, mx, ans);
    int siz=q.size();
    if(siz)
    {
        for(int i=1; i<=siz; i++)
        {
            sumstep[i]=sumstep[i-1]+q[i-1].first-q[i-1].second;
            sumspid[i]=sumspid[i-1]+c[i-1];
            det[i]=sumstep[i]-sumspid[i];
        }
        for(int i=1; i<siz; i++)h[i]=det[i]+q[i].first-q[i].second;
        ok[0]=1;
        for(int i=1; i<siz; i++)
        {
            if(ok[i-1]&&det[i]>0)ok[i]=1;
            else ok[i]=0;
        }
        init();
        for(int i=0; i<siz; i++)
        {
            if(sumstep[siz]+q[i].second<l)continue;
            if(ok[i]==0)continue;
            int day=lower_bound(sumstep,sumstep+1+siz,l-q[i].second)-sumstep;
            if(day<=i)
                ans=min(ans,day+1);
            else if(day==i+1)
                ans=min(ans,day);
            long long qry=query(i+1,day-1);
            if(qry==inf)continue;
            if(qry<=(q[i].first-q[i].second))
                continue;
            else
            {
                if(day>i+1)
                    ans=min(ans,day);
                else
                    ans=min(ans,day+1);
            }
        }
        l-=q[siz-1].first;
        int day=inf;
        if(l<=0)day=1;
        for(int i=1; i<=siz-1; i++)
        {
            if(sumstep[i]<=sumspid[i])break;
            if(sumstep[i]>=l)
            {
                day=i+1;
                break;
            }
        }
        ans=min(ans,day);
    }
    printf("%d\n",ans==inf?-1:ans);
    return 0;
}
