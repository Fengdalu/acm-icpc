#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define LL long long
#define PII pair<int, int>
#define AA first
#define BB second

int f[200][200];

int main()
{
//    freopen("input.txt", "r", stdin);
    int n, m, x;
    while(~scanf("%d%d", &n, &m))
    {
        LL ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                scanf("%d", &x);
                f[i][j] = x;
                ans += (LL)x;
            }
        if(n & 1)
        {
            int flg = 0;
            printf("%I64d\n", ans);
            for(int i = 0; i < n; i++)
            {
                flg ^= 1;
                for(int i = 0; i < m - 1; i++)
                {
                    if(flg) printf("R");
                    else printf("L");
                }
                if(i != n - 1) printf("D");
            }
            printf("\n");
        }
        else if(m & 1)
        {
            int flg = 0;
            printf("%I64d\n", ans);
            for(int i = 0; i < m; i++)
            {
                flg ^= 1;
                for(int i = 0; i < n - 1; i++)
                {
                    if(flg) printf("D");
                    else printf("U");
                }
                if(i != m - 1) printf("R");
            }
            printf("\n");
        }
        else
        {
            PII p;
            if(n >= 2) p = PII(1, 0);
            else p = PII(0, 1);
            for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
            if((i + j) & 1)
            {
                if(f[i][j] < f[p.AA][p.BB]) p = PII(i, j);
            }
//            cout << "PT " << p.AA << " " << p.BB << endl;
            printf("%I64d\n", ans - (LL)f[p.AA][p.BB]);
            if(p.AA % 2 == 0)
            {
                int flg = 0;
                for(int i = 0; i < p.AA; i++)
                {
                    flg ^= 1;
                    for(int i = 0; i < m - 1; i++)
                        if(flg) printf("R"); else printf("L");
                    printf("D");
                }

                flg = 0;
                for(int i = 0; i < m; i++)
                {
                    if(i != p.BB)
                    {
                        flg ^= 1;
                        if(flg) printf("D");
                        else printf("U");
                        if(i != m - 1) printf("R");
                    }
                    else
                    {
                        if(p.AA + 1 == n - 1 && p.BB == m - 1) break;
                        if(p.BB + 1 < m)printf("R");
                    }
                }
                if(p.AA + 1 != n - 1)
                {
                    printf("D");
                    int flg = 0;
                    for(int i = p.AA + 2; i < n; i++)
                    {
                        flg ^= 1;
                        for(int j = 0; j < m - 1; j++)
                        {
                            if(flg) printf("L"); else printf("R");
                        }
                        if(i != n - 1) printf("D");
                    }
                }
            }
            else
            {
                int flg = 0;
                for(int i = 0; i < p.BB; i++)
                {
                    flg ^= 1;
                    for(int i = 0; i < n - 1; i++)
                        if(flg) printf("D"); else printf("U");
                    printf("R");
                }
                flg = 0;
                for(int i = 0; i < n; i++)
                {
                    if(i != p.AA)
                    {
                        flg ^= 1;
                        if(flg) printf("R");
                        else printf("L");
                        if(i != n - 1) printf("D");
                    }
                    else
                    {
                        if(p.AA == n - 1 && p.BB + 1 == m - 1) break;
                        if(p.AA + 1 < n) printf("D");
                    }
                }
                if(p.BB + 1 != m - 1)
                {
                    printf("R");
                    int flg = 0;
                    for(int i = p.BB + 2; i < m; i++)
                    {
                        flg ^= 1;
                        for(int j = 0; j < n - 1; j++)
                        {
                            if(flg) printf("U"); else printf("D");
                        }
                        if(i != m - 1) printf("R");
                    }
                }
            }
            printf("\n");
        }
    }
    return 0;
}

