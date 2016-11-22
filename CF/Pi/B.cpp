#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a, b;
char tmp[5];
int x[1000100];
bool op[200];
bool vis[1000010], vis1[1000010];

int main()
{
    a = 0; b = 0;
    memset(vis, 0, sizeof vis);
    memset(vis1, 0, sizeof vis1);
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s%d", tmp, &x[i]);
        if(!strcmp(tmp, "+")) op[i] = true; else op[i] = false;
    }
    for(int i = 0; i < n; i++)
    {
        if(op[i]) vis1[x[i]] = true;
        else if(!vis1[x[i]]) { vis[x[i]] = true; b++; }
    }
    if(b > a) a = b;
    for(int i = 0; i < n; i++)
    {
        if(op[i]) { vis[x[i]] = true; b++; }
        else { vis[x[i]] = false; b--; }
        if(b > a) a = b;
    }
    printf("%d\n", a);
    return 0;
}
