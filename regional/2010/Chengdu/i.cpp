#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;
int n,k;
int hp[50005];
bool vis[50005];
long long cal(long long p,long long cnt,long long sumk2,long long sumk,long long j)
{
    return cnt*p-(sumk2-j*sumk-j*sumk+j*j*cnt);
}
bool check(long long p)
{
    long long need=0;
    memset(vis,0,sizeof(vis));
    queue< pair<long long,pair<long long,long long> > >s;
    long long d=(long long)ceil(sqrt(p));
    long long sumk=0;
    long long sumk2=0;
    long long cnt=0;
    for(int i=n-1;i>=0;i--)
    {
        if(vis[i])
        {
            pair<long long, pair<long long,long long> >head= s.front();
            long long CNT=head.second.second;
            long long K=head.second.first;
            cnt-=CNT;
            sumk-=CNT*K;
            sumk2-=CNT*K*K;
            s.pop();
        }
        long long atk=cal(p,cnt,sumk2,sumk,i);
        if(hp[i]<atk);
        else
        {
            long long res=hp[i]-atk;
            long long nd=res/p+(res%p==0);
            need+=nd;
            sumk+=nd*i;
            sumk2+=nd*i*i;
            s.push(make_pair(d-i,make_pair(i,nd)));
//            s.push(make_pair(i-d,make_pair(i,nd)));
            if(i-d>=0)vis[i-d]=1;
        }
    }
    return need<=k;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
            scanf("%d",&hp[i]);
        long long L=1,R=(1LL<<62);
        while(L<R)
        {
            long long mid=(L+R)/2;
            if(check(mid))
                R=mid;
            else
                L=mid+1;
        }
        cout << L << endl;
    }
    return 0;
}
