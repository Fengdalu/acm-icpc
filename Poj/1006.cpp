#include <stdio.h>
#include <stdlib.h>



int main()
{
    int ii = 0;
    while(1)
    {
        int p, e, i, d;
        scanf("%d%d%d%d", &p, &e, &i, &d);
        if (p == -1) break;
        
        p %= 23;
        e %= 28;
        i %= 33;
        
        int ans = p * 5544 + e * 14421 + i * 1288;
        ans %= 21252;
        
        ans -= d;
        if (ans <= 0) ans += 21252;
        
        printf("Case %d: the next triple peak occurs in %d days.\n", ++ii, ans);
    }
    
    return 0;
}