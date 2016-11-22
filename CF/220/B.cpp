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


char s[200000];

int main()
{
    LL ans = 1;
    scanf("%s", s);
    int len = strlen(s);
    int cc = 0;
    for(int i = 1; i < len; i++)
    {
        if(s[i] - '0' + s[i - 1] - '0' == 9) cc++;
        else { if(cc != 0) { if(cc % 2 == 0) ans *= (LL)(cc / 2) + 1; } cc = 0; }
    }
    if(cc != 0) { if(cc % 2 == 0) ans *= (LL)(cc / 2) + 1; } cc = 0;
    printf("%I64d\n", ans);
    return 0;
}