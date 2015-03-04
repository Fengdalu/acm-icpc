#include <iostream>
#include <cstdio>
#define N 8

using namespace std;

int f[N][N];
char s[100];

bool check()
{  
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
           if(f[i][j] == f[i][j + 1]) return false;
        for(int j = 0; j < 7; j++)
            if(f[i][j] == f[i + 1][j]) return false;
    }
    return true;
}

bool left(int r)
{
   int c = f[r][7]; 
   for(int i = 7; i > 0; i--) f[r][i] = f[r][i - 1];
   f[r][0] = c; 
}

bool right(int r)
{
    int c = f[r][0];
    for(int i = 0; i < 7; i++) f[r][i] = f[r][i + 1];
    f[r][7] = c;
}

void disp()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
            printf("%d", f[i][j]);
        putchar('\n');
    }
}
bool dfs(int r)
{
   if(r == 8) return false;
   if(check()) return true;
   for(int i = 0; i < 7; i++)
   {
       left(r);
       if(dfs(r + 1)) return true;
    } 
   left(r);
   return false;
}

int main()
{
   for(int i = 0; i < 8; i++) 
   {
       scanf("%s", s);
       for(int j = 0; j < 8; j++)
           f[i][j] = (s[j] == 'W') ? 1 : 0;
   }
   if(dfs(0)) puts("YES"); else puts("NO");
   return 0;
}

