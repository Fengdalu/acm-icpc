#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define PII pair<int, int>
#define PB(x) push_back(x)
#define AA first
#define BB second
#define N 5000

vector<int>s[N];
vector<int>tmp;
int cnt;

int a[N];
bool vis[N];
int n, k;

void cal()
{
    cnt = 0;
    memset(vis, 0, sizeof vis);
    for(int i = 1; i <= n; i++) if(!vis[i])
    {
        int t = i;
        s[cnt].clear();
        while(!vis[t])
        {
            vis[t] = true;
            s[cnt].PB(t);
            t = a[t];
        }
        cnt++;
    }
    for(int i = 0; i < cnt; i++) sort(s[i].begin(), s[i].end());
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    cal();
    int op = n - cnt;
    scanf("%d", &k);
    if(op < k)
    {
        tmp.clear();
        for(int i = 0; i < cnt; i++) tmp.PB(s[i][0]);
        sort(tmp.begin(), tmp.end());
        int nn = k - op;
        printf("%d\n", nn);
        for(int i = 1; i <= nn; i++) printf("%d %d ", tmp[0], tmp[i]);
    }
    else if(op > k)
    {
        printf("%d\n", op - k);
        for(int i = 0; i < op - k; i++)
        {
            PII x(n + 1, n + 1);
            cal();
            for(int i = 0; i < cnt; i++)
            if(s[i].size() > 1)
            {
                PII t(s[i][0], s[i][1]);
                x = min(x, t);
            }
            swap(a[x.AA], a[x.BB]);
            printf("%d %d ", x.AA, x.BB);
        }
    }
    else printf("0\n");
    return 0;
}
