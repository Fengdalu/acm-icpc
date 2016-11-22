#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

bool vis[3000];
int c[3000];
int q[3000];
int c1[3000];
int n, m; 

long long cal()
{
    long long ans = 0;
    for(int i = 0; i < m; i++)
    {
        int j = 0;
        for(;j < n; j++)
        if(c1[j] == q[i]) break;
        int t = c1[j]; 
        for(int k = j; k >= 1; k--)
            c1[k] = c1[k - 1];
        c1[0] = t; 
        for(int k = 1; k <= j; k++) ans += (long long)c[c1[k]];
    }
    return ans;
}
        

int main()
{
   scanf("%d%d", &n, &m) ;
   for(int i = 0; i < n; i++) scanf("%d", &c[i]);
   for(int i = 0; i < m; i++) scanf("%d", &q[i]);
   for(int i = 0; i < m; i++) q[i]--;
   memset(vis, 0, sizeof vis);
   
   int cnt = 0;
   for(int i = 0; i < m; i++)
   if(!vis[q[i]])
   {
      vis[q[i]] = true; 
     c1[cnt++] = q[i]; 
   }
   cout << cal() <<endl;
   return 0;
}
