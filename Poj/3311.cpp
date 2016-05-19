#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define INF 1000000000

using namespace std;

int n;
int d[20][20];
int f[20];

int find(int x, int p)
{
    if (p == n) return d[x][0];
    f[x] = 1;
    int ans = INF;
    
    for (int i = 0; i < n; i++)
    {
        if (!f[i])
        {
            int tmp = find(i, p + 1) + d[x][i];
            if (tmp < ans) ans = tmp;
        }
    }
    f[x] = 0;
    return ans;
}


int main()
{
    while(true)
    {
        cin >> n;
        if (n == 0) break;
        n++;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                cin >> d[i][j];
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    d[j][k] = min(d[j][i] + d[i][k], d[j][k]);
        memset(f, 0, sizeof f);
        cout << find(0, 1) << endl;
    }	
    return 0;	
}