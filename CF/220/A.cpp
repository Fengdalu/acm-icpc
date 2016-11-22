#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL long long
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define PII pair<int, int>
#define AA first
#define BB second

int n, m, i, j, a, b;
int main()
{
    scanf("%d%d%d%d%d%d", &n, &m, &i, &j, &a, &b);
    if((n - i) % a != 0 && (i - 1) % a != 0) { puts("Poor Inna and pony!"); return 0; }
    if((m - j) % b != 0 && (j - 1) % b != 0) { puts("Poor Inna and pony!"); return 0; }
    if((i == 1 || i == n) && (j == 1 || j == m)) { puts("0"); return 0; }
    if((i + a > n && i - a < 1) || (j + b > m && j - b < 1))  { puts("Poor Inna and pony!"); return 0; }
    int ans = 2000000;
    if( (n - i) % a == 0 && (m - j) % b == 0 )
    {
        if(abs((n - i) / a - (m - j) / b) % 2 == 0) ans = min(ans, max((n - i) / a, (m - j) / b));
    }
    if( (n - i) % a == 0 && (j - 1) % b == 0 )
    {
        if(abs((n - i) / a - (j - 1) / b) % 2 == 0) ans = min(ans, max((n - i) / a, (j - 1) / b));
    }
    if( (i - 1) % a == 0 && (j - 1) % b == 0 )
    {
        if(abs((i - 1) / a - (j - 1) / b) % 2 == 0) ans = min(ans, max((i - 1) / a, (j - 1) / b));
    }
    if( (i - 1) % a == 0 && (m - j) % b == 0 )
    {
        if(abs((i - 1) / a - (m - j) / b) % 2 == 0) ans = min(ans, max((i - 1) / a, (m - j) / b));
    }
    if(ans != 2000000) printf("%d\n", ans);
    else printf("Poor Inna and pony!\n");
    return 0;
}