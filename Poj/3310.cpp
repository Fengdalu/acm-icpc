#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

int a[433], b[433];
int f[211];
int n, m;

int find(int x)
{
    if (f[x] == x) return x;
    f[x] = find(f[x]);
    return f[x];
}

int main()
{
    int ii = 1;
    while(true)
    {
        bool flg = false;
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%d", &m);
        for (int i = 0; i <= n; i++) f[i] = i;
        int j, k;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &a[i], &b[i]);
            if (find(a[i]) == find(b[i]))
            {
                flg = true;
            }
            if (!flg) f[find(a[i])] = b[i];
        }
        
        if (flg)
        {
            cout << "Graph " << ii++ <<" is not a caterpillar."<< endl;
            continue;
        }
        
        memset(f, 0, sizeof f);
        for (int i = 0; i < m; i++)
        {
            f[a[i]]++;
            f[b[i]]++;
        }
        
        for (int i = 1; i <= n; i++)
            if (f[i] == 1)
            {
                for (int j = 0; j < m; j++)
                {
                    if (a[j] == i || b[j] == i)
                    {
                        a[j] = 0;
                        b[j] = 0;
                    }
                }
            }
        memset(f, 0, sizeof f);
        for (int i = 0; i < m; i++) 
            if (a[i] != 0)
            {
                f[a[i]]++; 
                f[b[i]]++;
            }
        int cc = 0;
        for (int i = 1; i <= n; i++)	
        {
            if (f[i] == 1) cc++;
        }
        if (cc > 2 || m != n - 1) cout << "Graph " << ii++ <<" is not a caterpillar."<< endl;
        else 
            cout << "Graph " << ii++ <<" is a caterpillar."<< endl;
    }		
    return 0;
    
}