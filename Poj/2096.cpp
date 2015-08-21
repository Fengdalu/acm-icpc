#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define N 1010

int n, s;

double dp[N][N];
double cal(int i, int j)
{
    if(i == n && j == s) return 0;
    if(i > n || j > s) return 0;
    if(dp[i][j] != 0) return dp[i][j];
    double B = n * s - i * j;
    dp[i][j] = (n - i) * j / B * cal(i + 1, j)
    + (i) * (s - j) / B * cal(i, j + 1)
    + (n - i) * (s - j) / B * cal(i + 1, j + 1)
    + n * s / B;
    return dp[i][j];
}

int main()
{
    memset(dp, 0, sizeof dp);
    scanf("%d%d", &n, &s);
    printf("%.4f\n", cal(0, 0));
    return 0;
}