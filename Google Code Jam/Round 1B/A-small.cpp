#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define LL long long
LL s;
int f[2000000];

LL pow(int x, int k)
{
    LL ans = 1;
    while(k)
    {
        if(k & 1) ans *= x;
        k /= 2; x *= x;
    }
    return ans;
}

int cal(int x)
{
    static char buf[10];
    sprintf(buf, "%d", x);
    int len = strlen(buf);
    for(int i = 0; i < len / 2; i++) swap(buf[i], buf[len - 1 - i]);
    return atoi(buf);
}

void init()
{
    for(int i = 0; i <= 20; i++)
    {
        f[i] = i;
    }
    for(int i = 21; i <= 1000000; i++)
    {
        f[i] = f[i - 1] + 1;
        if(i % 10 != 0 && cal(i) <= i)
        {
            f[i] = min(f[i - 1] + 1, f[cal(i)] + 1);
        }
    }
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.txt", "w", stdout);
    init();
    //cout << "over" << endl;
    int T; scanf("%d", &T);
    for(int ii = 0; ii < T; ii++)
    {
        int n;
        scanf("%d", &n);
        printf("Case #%d: %d\n", ii + 1, f[n]);
    }

    return 0;
}
