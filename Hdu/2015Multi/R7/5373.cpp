#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int buf;
int n, t;

int bit(int x)
{
    if(x == 0) return 1;
    int ans = 0;
    while(x)
    {
        ans++;
        x /= 10;
    }
    return ans;
}

int getsum(int x)
{
    int sum = 0;
    while(x)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}


int qpp[10];
void init()
{
    qpp[1] = 10;
    for(int i = 2; i < 10; i++) qpp[i] = qpp[i - 1] * 10;
}

int qpow(int x, int p)
{
    return qpp[p];
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    init();
    int T = 0;
    while(~scanf("%d%d", &n, &t))
    {
        if(n == -1 && t == -1) break;
        int mod = n;
        int sum = getsum(n);
        mod %= 11;

        while(t--)
        {
            mod = qpow(10, bit(sum)) * mod + sum;
            mod %= 11;
            sum += getsum(sum);
        }
        mod %= 11;
        printf("Case #%d: ", ++T);
        if(!mod)puts("Yes"); else puts("No");
    }
    return 0;
}

