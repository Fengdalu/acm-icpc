#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int f[3][3];
bool vis[3][3];

int row(int r)
{
    int sum = 0;
    for(int i = 0; i < 3; i++)
        if(f[r][i] == 0) return -1;
        else sum += f[r][i];
    return sum;
}

int col(int c)
{
    int sum = 0;
    for(int i = 0; i < 3; i++)
        if(f[i][c] == 0) return -1;
        else sum += f[i][c];
    return sum;
}


bool chk()
{
   int p = row(0);
   for(int i = 1; i < 3; i++) if(row(i) != p) return false;
   for(int i = 0; i < 3; i++) if(col(i) != p) return false;
   for(int i = 0; i < 3; i++)
       for(int j = 0; j < 3; j++)
           if(f[i][j] > 100000 || f[i][j] <= 0) return false;
   if(f[0][0] + f[1][1] + f[2][2] != p) return false;
   if(f[0][2] + f[1][1] + f[2][0] != p) return false;
   return true;
}

void fill(int s)
{
    for(int i = 0; i < 3; i++)
    {
        int sum = 0;
        for(int j = 0; j < 3; j++) if(!vis[i][j]) sum += f[i][j];
        for(int j = 0; j < 3; j++) if(vis[i][j]) f[i][j] = s - sum;
    }
}

void print()
{
   for(int i = 0; i < 3; i++) 
   {
       for(int j = 0; j < 3; j++)
           if (j == 0)printf("%d", f[i][j]);
            else printf(" %d", f[i][j]);
        putchar('\n');
   }
}

int main()
{
 memset(vis, 0, sizeof vis);
   for(int i = 0; i < 3; i++) 
       for(int j = 0; j < 3; j++)
       {
           scanf("%d", &f[i][j]);
           if(f[i][j] == 0) vis[i][j] = true; else vis[i][j] = false;
       }
   int x, y;
   for(int i = 0; i < 3; i++) 
   {
       bool flg = false;
       for(int j = 0; j < 3; j++)
           if(f[i][j] == 0) { x = i; y = j; flg = true; break; }
       if(flg) break;
   }
    for(int i = 1; i <= 100000; i++)   
    {
        f[x][y] = i;
        int p = -1;
        for(int j = 0; j < 3; j++)   
          p = max(p, row(j));
        if(p == -1)
            for(int j = 0; j < 3; j++)
                p = max(p, col(j));
        fill(p);
        if(chk()) { print(); return 0;}
    }
   return 0; 
}
