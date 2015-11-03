#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <algorithm>
#include <set>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
#define LL long long
#define PII pair<int, int>
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
#define PII pair<int, int>
#define N 20005
#define PB(x) push_back(x)

LL dp[100][100];
char s[100];

LL cal(int L, int R)
{
    if(L == R) return 1;
    if(L > R) return 0;
    if(dp[L][R] != -1) return dp[L][R];
    if(s[L] == s[R]) dp[L][R] = cal(L + 1, R) + cal(L, R - 1) + 1;
    else dp[L][R] = cal(L + 1, R) + cal(L, R - 1) - cal(L + 1, R - 1);
    return dp[L][R];
}

int main()
{
    int _T; scanf("%d", &_T);
    for(int _CAS = 1; _CAS <= _T; _CAS++)
    {
        memset(dp, -1, sizeof dp);
        scanf("%s", s);
        printf("Case %d: %lld\n", _CAS, cal(0, strlen(s) - 1));
    }
    return 0;
}
