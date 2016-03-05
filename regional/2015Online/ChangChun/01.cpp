#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
#define AA first
#define BB second
#define N 150010
#define M 200010
#define LL long long
#define PII pair<int, int>
#define PPP pair< PII, int >

string name[N];
struct node
{
    int s;
    int c, no;
    node(int c, int no) : c(c), no(no) {}
    node() {}
    int operator < (const node &b) const
    {
        if(c == b.c) return no > b.no;
        return c < b.c;
    }

} a[N];
int n, m, q;
int c[N];
PPP Q[200];
char buf[300];
priority_queue<node>s;
int T;

int ans[N];

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &n, &m, &q);
        for(int i = 1; i <= n; i++)
        {
            scanf("%s%d", buf, &a[i].c);
            name[i] = string(buf);
            a[i].s = i;
            a[i].no = i;
        }
        memset(c, 0, sizeof c);
        for(int i = 0; i < m; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            c[x] += y;
        }

        while(s.size()) s.pop();

        int cnt = 0;
        int order = 1;
        for(int i = 1; i <= n; i++)
        {
            s.push(a[i]);
            int left = c[i];
            while(left && s.size())
            {
                ans[++cnt] = s.top().s;
                s.pop();
                left--;
            }
        }
        while(s.size())
        {
            ans[++cnt]=s.top().s;
            s.pop();
        }

        for(int i = 0; i < q; i++)
        {
            int que;
            scanf("%d",&que);
            if(i)
            printf(" ");
            printf("%s",name[ans[que]].c_str());
//            Q[i].AA.BB = i;
//            scanf("%d", &Q[i].AA.AA);
        }
        printf("\n");
    }
    return 0;
}