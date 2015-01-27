#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 10000000000

using namespace std;

long long f[20000];
int T, n, m;

int main()
{
   scanf("%d", &T);
   for(int ii = 0; ii < T; ii++)
   {
       for(int i = 0; i < 20000; i++) f[i] = INF; 
       f[0] = 0;
       int x, y;
       scanf("%d%d", &x, &y);
       n = y - x;
       scanf("%d", &m);
       for(int i = 0; i < m; i++)
       {
           int w;
           long v;
           scanf("%I64d%d", &v, &w);
           for(int i = 0; i + w <= n; i++)
              f[i + w] = min(f[i + w], f[i] + v);
       }
       if(f[n] == INF) puts("This is impossible.");
       else printf("The minimum amount of money in the piggy-bank is %I64d.\n", f[n]);
   }
   return 0;
}
