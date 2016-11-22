#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int f[400];
bool vis[400];
int c[400];
char s[400];

int find(int x)
{
    if(f[x] == x) return x;
    f[x] = find(f[x]);
    return f[x];
}

int main()
{
   memset(vis, 0, sizeof vis);
   int n;
   scanf("%d", &n);
   for(int i = 0; i < n; i++)
   {    
       scanf("%d", &c[i]); f[i] = i;
   }
   for(int i = 0; i < n; i++ )   
   {
       scanf("%s", s);
       for(int j = 0; j < n; j++)
        if(s[j] == '1')
        {
            f[find(i)] = find(j);
        }
   }
    for(int i = 0; i < n; i++) 
    {
      int  col = find(i);
        int p = -1;
        for(int j = 0; j < n; j++)
        if(!vis[j] && find(j) == col)
        {
            if(p == -1 || c[p] > c[j]) p = j;
        }
        if(i == 0) printf("%d", c[p]); 
        else printf(" %d", c[p]);
        vis[p] = true;
    }
    putchar('\n');
    return 0;
}

