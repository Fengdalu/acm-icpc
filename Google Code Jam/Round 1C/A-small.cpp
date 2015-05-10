#include <iostream>
#include <cstdio>
using namespace std;



int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int T, R, C, W;
    scanf("%d", &T);
    for(int ii = 0; ii < T; ii++)
    {
        scanf("%d%d%d", &R, &C, &W);
        int p = C / W;
        if(C % W != 0) p++;
        p--;
        int ans = (R - 1) * (p + 1) + p + W;
        printf("Case #%d: %d\n", ii + 1, ans);
    }
    return 0;
}
