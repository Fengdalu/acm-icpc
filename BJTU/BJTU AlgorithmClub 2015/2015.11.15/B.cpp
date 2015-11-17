#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int G[100][10];
int tot[10];

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                scanf("%d", &G[i][j]);
            }
        }
        memset(tot, 0, sizeof tot);
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
            tot[j] += G[i][j];
        for(int i = 0; i < n; i++)
        {
            int tot = 0;
            for(int j = 0; j < m; j++) tot += G[i][j];
            if(!i) printf("%.2f", (double)tot / m);
            else printf(" %.2f", (double)tot / m);
        }
        puts("");
        for(int i = 0; i < m; i++) if(!i) printf("%.2f", (double)tot[i] / n);
        else printf(" %.2f", (double)tot[i] / n);
        puts("");
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            bool flg = true;
            for(int j = 0; j < m; j++)
                if(n * G[i][j] < tot[j]) flg = false;
            if(flg) cnt++;
        }
        printf("%d\n\n", cnt);
    }
    return 0;
}

