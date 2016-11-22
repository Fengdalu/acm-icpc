#include <stdio.h>

int main()
{
    freopen("powers.in", "r", stdin);
    int t;
    scanf("%d",&t);
    int s = 0;
    int g;
    int x,y;
    while(t--)
    {
        s = 0;
        scanf("%d",&g);
        while(g--){scanf("%d%d",&x,&y);
        int ans;
        if(x & 1) ans = y & 1;
        else
        {
            y %= (x + 1);
            if(y == x) ans = 2;
            else ans = y & 1;
        }
        s ^= ans;
        }
        if(s) puts("1"); else puts("2");
    }
}
