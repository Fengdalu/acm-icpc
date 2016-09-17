#include <stdio.h>
#include <string.h>

const int N = 100000 + 5;
const int M = 500000 + 5;

int f[N];
int getf(int x)
{
    if(x == f[x]) return x;
    return f[x] = getf(f[x]);
}

void uni(int x, int y)
{
    int fx = getf(x);
    int fy = getf(y);
    f[fy] = fx;
}

int a[N];
int d[N];
int c[10];
int run()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
    for(int i = 1; i <= n; i++) f[i] = i;
    int x,y;
    for(int i = 1; i <= n; i++) d[i] = 0;
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        uni(x,y);
        d[x]++;
        d[y]++;
    }
    bool flag = true;
    int numj = 0;
    for(int i = 1; i <= n; i++)
        if(getf(i) != getf(1))
            flag = false;
    if(!flag) return -1;
    for(int i = 1; i <= n; i++) if(d[i] & 1)
    {
        c[numj++] = i;
        if(numj > 2) return -1;
    }
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        if(((d[i] + 1) >> 1) & 1) sum ^= a[i];
    }
    int ret = 0;
    if(numj == 2) ret = sum;
    else {
        ret = sum ^ a[1];
        for(int i = 1; i <= n; i++)
            if(ret < (sum ^ a[i]))
                ret = sum ^ a[i];
    }
    return ret;
}
int main()
{
    int _t;
    scanf("%d",&_t);
    while(_t--)
    {
        int ret = run();
        if(~ret) printf("%d\n", ret);
        else puts("Impossible");
    }
}
