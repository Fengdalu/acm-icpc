#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 2000000009

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        int n; scanf("%d", &n);
        int a = INF, b = INF;
        while(n--)
        {
            int x; scanf("%d", &x);
            for(int i = 2; i * i <= x; i++)
            while(x % i == 0)
            {
                if(i < a) a = i;
                if(a < b) swap(a, b);
                x /= i;
            }
            if(x != 1)
            {
                if(x < a) a = x;
                if(a < b) swap(a, b);
            }
        }
        if(a == INF || b == INF) puts("-1");
        else printf("%I64d\n", (long long)a * b);
    }
    return 0;
}
