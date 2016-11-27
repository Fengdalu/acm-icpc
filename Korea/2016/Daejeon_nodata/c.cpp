#include <stdio.h>
#include <queue>
const int inf = 1000000000;
const int none = -inf - inf - 10;
const int N = 100000 + 10;
int cnt[N];
int a[N];
int b[N];
int n,m;
#define AA first
#define BB second
typedef std::pair<int,int> pii;
typedef std::pair<pii,int> piii;
#define MP3(x,y,z) std::make_pair(std::make_pair(x,y), z)
std::priority_queue<piii> q;
int check(int d)
{
    for(int i = 0; i <= m; i++) cnt[i] = 0;
    int tot = 0;
    for(int i = 0; i < n; i++)
    {
        q.push(MP3(a[i] - d, -1, b[i]));
        q.push(MP3(a[i] + d, +1, b[i]));
    }
    int ret = none;
    piii t;
    while(!q.empty())
    {
        t = q.top();
        q.pop();
        if(t.AA.BB == -1)
        {
            cnt[t.AA.BB]++;
            if(cnt[t.AA.BB] == 1) tot++;
            if(tot == m && ret == none) ret = t.AA.AA;
        }
        else
        {
            cnt[t.AA.BB]--;
            if(cnt[t.AA.BB] == 0) tot--;
        }
    }
    return ret;
}
int main()
{
    while(scanf("%d%d",&m,&n) != EOF)
    {
        for(int i = 0; i < n; i++)
            scanf("%d%d", a + i, b + i);
        int l = 0;
        int r = inf;
        int ans = none;
        while(l < r)
        {
            int mid = (l + r) / 2;
            int ret = check(mid);
            if(ret != none) r = mid, ans = ret;
            else l = mid + 1;
        }
        printf("%d\n", l);
        printf("%d\n", ans);
    }
}
