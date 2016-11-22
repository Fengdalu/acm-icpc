#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define M 200010
#define N 100010

using namespace std;

int t[M], nt[M];
int ind[N];
bool vis[N];
int c[N];
int n;
int cnt;
int fr[N], to[N], v[N];

void add(int a, int b)
{
    cnt++;
    t[cnt] = b;
    nt[cnt] = ind[a];
    ind[a] = cnt;
} 
    
void dfs(int x)
{
    vis[x] = true;
   for(int k = ind[x]; k != -1; k = nt[k])
    if(!vis[t[k]])
   {
     dfs(t[k]);
     c[x] += c[t[k]];
   }
   c[x]++;
}

int main()
{
   scanf("%d", &n);
   for(int i = 1; i <= n; i++) ind[i] = -1;
   cnt = 0;
   for(int i = 0; i < n - 1; i++)
   {
        int x, y, z;
       scanf("%d%d%d", &x, &y, &z);
       fr[i] = x; to[i] = y; v[i] = z;
       add(x, y); add(y, x);
   }
   memset(c, 0, sizeof c);
   memset(vis, 0, sizeof vis);
   dfs(1);
   double ans1 = 0;
   for(int i = 0; i < n - 1; i++) 
   {
       double t1 = min(c[fr[i]], c[to[i]]);
       double t2 = n - t1;
       double cc = 0;
       if(t1 >= 2) cc += (t1 * (t1 - 1) / 2 * t2) * 2;
       if(t2 >= 2) cc += (t2 * (t2 - 1) / 2 * t1) * 2;
      ans1 += (double)cc * (double)v[i];
   }
   
   int nn;
   scanf("%d", &nn);
   double ans = ans1;
  double b = (double)(n) * (double)(n - 1) * (double)(n - 2) / 6; 
  for(int i = 0; i < nn; i++) 
  {
      int x, y;
      scanf("%d%d", &x, &y);
      x--;
      double t1 = min(c[fr[x]], c[to[x]]);
      double t2 = n - t1;
      double  cc = 0;
       if(t1 >= 2) cc += (t1 * (t1 - 1) / 2 * t2) * 2;
       if(t2 >= 2) cc += (t2 * (t2 - 1) / 2 * t1) * 2;
       double  ans1 = ans - (double)cc * (double)v[x] + (double)cc * (double)y;
       printf("%.10f\n", ans1 / b);
       ans = ans1;
       v[x] = y;
  }
 return 0;
}
