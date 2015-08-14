#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

long long f[200];
long long a[200][200];
int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    memset(f, 0, sizeof f); int x;
    for(int i = 0; i < m; i++) for(int j = 0; j < n; j++) scanf("%d", &a[i][j]);
    for(int i = 0; i < m; i++)
    {
        int x = 0;
        for(int j = 0; j < n; j++) if(a[i][j] > a[i][x]) x = j;
        f[x]++;
    }
    x = 0;
    for(int i = 0; i < n; i++) if(f[i] > f[x]) x = i;
    printf("%d\n", x + 1);
}

