#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, x, y;
int main()
{
    //freopen("input.txt", "r", stdin);
    while(~scanf("%d%d%d%d", &n, &m, &x, &y))
    {
        if(n == 1 && m == 1) { printf("0\n"); continue; }
        if(n == 1 || m == 1) { printf("1\n"); continue; }

        if(n < m) { swap(n, m); swap(x, y); }
        if(x > n / 2) x = (n - x) + 1;
        if(y > m / 2) y = (m - y) + 1;
        //cout << n << " " << m << " " << x << " " << y << endl;

        if((n & 1) && (m & 1) && x == (n + 1) / 2 && y == (m + 1) / 2)
        {
            printf("%d\n", max(n / 2, m / 2));
        }
        else
        {
            int A = -1, B = -1;
            int w = n - x, h = m;
            A = min((h + 1) / 2, w);
            B = min(x, h - y);
            //cout <<"AB: " << A << " " << B << endl;
            int ans = max(A, B);
            printf("%d\n", ans);
        }
    }
    return 0;
}
