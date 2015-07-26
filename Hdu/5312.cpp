#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
#define N 10010
#define M 200010
#define LL long long

bool chk(int x)
{
    x = x - 1;
    if(x % 3 != 0) return false;
    int p = x / 3;
    p = p * 4 + 1;
    int y = (int)sqrt(p);
    if(y * y == p) return true;
    return false;
}

int main()
{
    //freopen("d:\in.txt", "r", stdin);
    int T; scanf("%d", &T);
    while(T--)
    {
        //printf("CASE: \n");
        int m; scanf("%d", &m);
        if(chk(m)) { puts("1"); continue; }
        bool flg = false;
        for(int i = 1; i <= 15000; i++)
        {
            int q1 = 3 * i * (i - 1) + 1;
            if(q1 > m) break;
            if(chk(m - q1)) { flg = true; break; }
        }
        if(flg) { puts("2"); continue; }
        int ss;
        for(int k = 3; ; k++) if((m - k) % 6 == 0) { ss = k; break; }
        printf("%d\n", ss);
    }
    return 0;
}
