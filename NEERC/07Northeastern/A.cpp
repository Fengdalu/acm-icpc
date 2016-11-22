#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define INF 1000000000
#define N 1000

using namespace std;

double x[N], y[N], x2[N], y2[N];
int link[N];
double lx[N], ly[N];
bool visx[N], visy[N];
double slack[N];
int n;

double sqr(double x) { return x * x; }

double dis(int i, int j)
{
    return -sqrt( sqr( x[i] - x2[j] ) + sqr( y[i] - y2[j] ) );
}

bool dcmp(double x) { if (fabs(x) < 1e-8) return 1; return 0; }

int dfs(int x)
{
    visx[x] = true;
    for(int i = 0; i < n; i++)
    {
        if(!visy[i])
        {
            double t = lx[x] + ly[i] - dis(x, i);
            if(dcmp(t))
            {
                visy[i] = true;
                if(link[i] == -1 || dfs(link[i]))
                {
                    link[i] = x;
                    return 1;
                }
            }
            else slack[i] = min(t, slack[i]);
        }
    }
    return 0;
}

int main()
{
    freopen("ants.in", "r", stdin);
    freopen("ants.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++) scanf("%lf%lf", &x2[i], &y2[i]);
    for(int i = 0; i < n; i++) scanf("%lf%lf", &x[i], &y[i]);

    memset(ly, 0, sizeof ly);
    for(int i = 0; i < n; i++) lx[i] = -INF;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            lx[i] = max(lx[i], dis(i, j));
            ly[i] = 0;
        }
    for(int i = 0; i < n; i++) 
    {
        link[i] = -1;
    }
    for(int x = 0; x < n; x++)
    {
        for(int i = 0; i < n; i++) slack[i] = INF;
        while(true)
        {
            memset(visx, 0, sizeof visx);
            memset(visy, 0, sizeof visy);
            if(dfs(x)) break;           
            double d = INF;
            for(int i = 0; i < n; i++)
                if(!visy[i]) d = min(d, slack[i]);
            for(int i = 0; i < n; i++)
                if(visx[i]) lx[i] -= d;
            for(int i = 0; i < n; i++)
            {
                if(visy[i]) ly[i] += d;
                else slack[i] -= d;
            }

        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << link[i] + 1 << endl;
    }
    fclose(stdout);
}