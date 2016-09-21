#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
long long a[20];
long long dp[20][2][3][2];
long long calc(long long n)
{
    if(n == 0) return 0;
    int tot = 0;
    long long nn = n;
    while(nn)
    {
        a[tot++] = nn % 10LL;
        nn /= 10;
    }
    std::reverse(a, a + tot);
    //for(int i = 0; i < tot; i++) printf("%lld", a[i]); puts("");
    memset(dp, 0, sizeof dp);
    dp[0][1][2][0] = 1;
    for(int i = 1; i < tot; i++)
        dp[i][0][2][0] = 1;
    for(int i = 0; i < tot; i++)
    {
        for(int flag = 0; flag < 2; flag++)
        {
            for(int st = 0; st < 3; st++)
            {
                for(int cnt = 0; cnt < 2; cnt++)
                {
                    if(dp[i][flag][st][cnt])
                    {
                        int _max_ = 9;
                        if(flag) _max_ = a[i] - 1;
                        //printf("\t NOW %d %d %d %d = %lld max = %d\n", i, flag, st, cnt, dp[i][flag][st][cnt], _max_);
                        if(flag)
                        {
                            if(st == 2)
                            {
                                dp[i + 1][1][a[i] & 1][1] += dp[i][flag][st][cnt];
                            }
                            else
                            {
                                if(st == (1LL & a[i]))
                                    dp[i + 1][1][st][cnt ^ 1] += dp[i][flag][st][cnt];
                                else if(st + cnt == 1)
                                    dp[i + 1][1][st ^ 1][1] += dp[i][flag][st][cnt];
                            }
                        }
                        for(int sel = 0; sel <= _max_; sel++)
                        {
                            if(sel == 0 && st == 2) continue;
                            if(st == 2)
                            {
                                dp[i + 1][0][sel & 1][1] += dp[i][flag][st][cnt];
                                //printf("\t\t %d %d %d %d add\n", i + 1, 0, i & 1, 1);
                            }
                            else
                            {
                                if(st == (1 & sel))
                                    dp[i + 1][0][st][cnt ^ 1] += dp[i][flag][st][cnt];
                                else if(st + cnt == 1)
                                    dp[i + 1][0][st ^ 1][1] += dp[i][flag][st][cnt];
                            }
                        }
                    }
                }
            }
        }
    }
    long long ret = 0;
    for(int flag = 0; flag < 2; flag++)
        for(int st = 0; st < 2; st++)
            ret += dp[tot][flag][st][st ^ 1];
    //printf("ret = %lld\n", ret);
    return ret;
}
void run()
{
    long long l,r;
    //scanf("%lld%lld",&l, &r);
    //printf("%lld\n", calc(r) - calc(l - 1));
    std::cin >> l >> r;
    long long ans = calc(r) - calc(l - 1);
    std::cout << ans << std::endl;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        run();
    }
}
