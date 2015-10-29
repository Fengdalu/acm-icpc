#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long
#define N 110
int dp[N][N];
int n, w, k;
int y[N];
int cc[N];

int main()
{
    int _T; scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS++)
    {
        scanf("%d%d%d", &n, &w, &k);
        for(int i = 0; i < n; i++)
        {
            int x; scanf("%d%d", &x, &y[i]);
        }
        sort(y, y + n);
        reverse(y, y + n);
        for(int i = 0; i < n; i++)
            for()
    }
    return 0;
}
