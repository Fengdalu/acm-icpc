#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long
#define N 200010

char a[N], b[N];
bool eq(int l1, int r1, int l2, int r2)
{
    for(int i = 0; i < r1 - l1 + 1; i++)
    {
        if(a[l1 + i] != b[l2 + i]) return false;
    }
    return true;
}

bool chk(int l1, int r1, int l2, int r2)
{
    if(r1 - l1 != r2 - l2) return false;
    if(eq(l1, r1, l2, r2)) return true;
    if((r1 - l1 + 1) % 2 == 0)
    {
        int h = (r1 - l1 + 1) / 2;
        if(chk(l1, l1 + h - 1, l2, l2 + h - 1) && chk(l1 + h, r1, l2 + h, r2)) return true;
        if(chk(l1, l1 + h - 1, l2 + h, r2) && chk(l1 + h, r1, l2, l2 + h - 1)) return true;
    }
    return false;
}

int main()
{
    scanf("%s%s", a, b);
    if(chk(0, strlen(a) - 1, 0, strlen(b) - 1)) puts("YES");
    else puts("NO");
    return 0;
}
