#include <cstdio>
#include <iostream>
#define MAXN 1006

using namespace std;

int f[MAXN][MAXN];
int q[MAXN];
int q1[MAXN];
int cnt, cnt1;

int main()
{
    int n;
    int ii = 0;
    while(true)
    {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &f[i][j]);
        
        for (int i = 0; 1 + i <= n - i; i++)
        {
            cnt = 0;
            if (1 + i != n - i)
            {
                for (int j = 1 + i; j < n - i; j++)q[cnt++] = f[1 + i][j];
                for (int j = 1 + i; j < n - i; j++)q[cnt++] = f[j][n - i];
                for (int j = n - i; j > 1 + i; j--)q[cnt++] = f[n - i][j];
                for (int j = n - i; j > 1 + i; j--)q[cnt++] = f[j][1 + i];
                
                int pos;
                int mm = 1000005;
                for (int j = 0; j < cnt; j++) if (q[j] < mm) {mm = q[j];pos = j;}
                cnt1 = 0;
                for(int j = 0; j < cnt; j++)
                {
                    q1[cnt1++] = q[(pos + j) % cnt];
                }
                
                cnt = 0;
                for (int j = 1 + i; j < n - i; j++) f[1 + i][j] = q1[cnt++];
                for (int j = 1 + i; j < n - i; j++) f[j][n - i] = q1[cnt++];
                for (int j = n - i; j > 1 + i; j--) f[n - i][j] = q1[cnt++];
                for (int j = n - i; j > 1 + i; j--) f[j][1 + i] = q1[cnt++];
            }
            else 
            {
                
            }
        }
        
        bool flg = true;
        for (int i = 1; i <= n; i++)
        {		
            for (int j = 1; j <= n; j++)
            {
                if(f[i][j] != (i - 1) * n + j) 
                {
                    flg = false;
                    break;
                }
            }
            if (!flg) break;
        }
        
        if (flg) printf("%d. YES\n", ++ii);
        else printf("%d. NO\n", ++ii);
    }
}