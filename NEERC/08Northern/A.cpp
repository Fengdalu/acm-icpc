#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct node
{
    int t[2];
    int id;
}f[5000000];
int root;
int cnt, n, m;
char s1[10], s2[10], s3[50];
bool chk[100100];

void insert(int s, int l, int id)
{
    int k = root;
    for(int j = 31; j >= 0 && l > 0; j--, l--)
    {
        int x = (s & (1 << j));
        x = (x != 0);
        if(f[k].t[x] == 0) f[k].t[x] = ++cnt;
        k = f[k].t[x];
    }
    if(f[k].id == 0) f[k].id = id;
}

int cal(int s)
{
    int k = root;
    int ans = n + 1;
    for(int j = 31; j >= 0; j--)
    {
        if(f[k].id != 0) ans = min(ans, f[k].id);
        int x = s & (1 << j); x = (x != 0);
        if(f[k].t[x] == 0) return ans;
        k = f[k].t[x];
    }
    if(f[k].id != 0) ans = min(ans, f[k].id);
    return ans;
}

int main()
{
    freopen("access.in", "r", stdin);
    freopen("access.out", "w", stdout);
    scanf("%d", &n);
    memset(chk, 0, sizeof chk);
    cnt = 0;
    memset(f, 0, sizeof f);
    root = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%s%s%s", s1, s2, s3);
        if(!strcmp(s1, "allow")) chk[i + 1] = true;
        else chk[i + 1] = false;
        bool ff = false;
        int len = strlen(s3);
        for(int i = 0; i < len; i++) if(s3[i] == '/')
            ff = true;
        int a, b, c, d, l;
        if(ff)
        {
            sscanf(s3, "%d.%d.%d.%d/%d", &a, &b, &c, &d, &l);
            insert(a << 24 | b << 16 | c << 8 | d, l, i + 1);
        }
        else
        {
            sscanf(s3, "%d.%d.%d.%d", &a, &b, &c, &d);
            insert(a << 24 | b << 16 | c << 8 | d, 32, i + 1);
        }
    }
    scanf("%d", &m);
    int a, b, c, d;
    for(int i = 0; i < m; i++)
    {
        scanf("%d.%d.%d.%d", &a, &b, &c, &d);
        int ans = cal(a << 24 | b << 16 | c << 8 | d);
        if(ans == n + 1) printf("A");
        else if(chk[ans]) printf("A");
        else printf("D");
    }
    printf("\n");
    fclose(stdout);
    return 0;
}
