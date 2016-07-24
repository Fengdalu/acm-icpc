#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 200000


int f[N];

int main()
{
    freopen("output.txt", "r", stdin);
    while(true)
    {
        int n; scanf("%d", &n);
        for(int i = 1; i <= n; i++) f[i] = n;
        int pos = n + 1;
        for(int i = 0; i < n - 1; i++)
        {
            int a, b; char buf[5];
            scanf("%d %s %d", &a, buf, &b);
            if(!strcmp(buf, "+")) f[pos] = f[a] + f[b];
            if(!strcmp(buf, "*")) f[pos] = f[a] * f[b];
            if(!strcmp(buf, "-")) f[pos] = f[a] - f[b];
            if(!strcmp(buf, "/")) f[pos] = f[a] / f[b];
            pos++;
        }
        if(f[pos - 1] != 24) printf("%d\n", f[pos - 1]);
        //printf("%d\n", f[pos - 1]);
    }
    return 0;
}
