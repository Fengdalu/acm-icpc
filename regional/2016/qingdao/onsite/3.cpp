#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        double l,d;
        scanf("%lf%lf",&l,&d);
        if(l<=d)
            printf("0.000000\n");
        else
            printf("%f\n",log(l)-log(d)+1);
    }
    return 0;
}
