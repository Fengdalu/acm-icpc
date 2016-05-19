#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct obj
{
    int a, b, c;
}e[200];

int f[200];
int n;
int nn;
int cnt = 0;
char t[5];

void add(int a, int b, int c)
{
    e[cnt].a = a;
    e[cnt].b = b;
    e[cnt].c = c;
    cnt++;
}

int find(int x)
{
    if (f[x] == x) return x;
    f[x] = find(f[x]);
    return f[x];
}

int cmp(obj a, obj b)
{
    return a.c < b.c;
}

int main()
{
    while(true)
    {
        scanf("%d", &n);
        cnt = 0;
        if (n == 0) break;
        for (int i = 0; i < n - 1; i++)
        {
            scanf("%s%d", t, &nn);
            int s = t[0] - 'A';
            int k;
            for (int j = 0; j < nn; j++)
            {
                //char tt = s + 'A';
                scanf("%s %d", t, &k);
                //cout << tt << " " << t << " " << k << endl;
                add(s, t[0] - 'A', k);
            }
        }
        
        for (int i = 0; i < n; i++) f[i] = i;
        sort(e, e + cnt, cmp);
        int ans = 0;
        for (int i = 0; i < cnt; i++)
        {
            if (find(e[i].a) == find(e[i].b)) continue;
            ans += e[i].c;
            f[find(e[i].a)] = find(e[i].b);
        }
        printf("%d\n", ans);
    }	
    return 0;
}