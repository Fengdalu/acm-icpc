#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int k,d;
    scanf("%d%d",&k,&d);
    if(d==0)
    {
        if(k==1)
            printf("0\n");
        else
            printf("No solution\n");
    }
    else
    {
        printf("%d",d);
        for(int i=1;i<k;i++)
            printf("0");
        printf("\n");
    }
    return 0;
}
