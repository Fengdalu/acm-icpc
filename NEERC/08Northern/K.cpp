#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

map<ll,int>::iterator it;
ll an[100];
ll n, m;

int main()
{
    freopen("key.in","r",stdin);
    freopen("key.out","w",stdout);
    while(~scanf("%I64d %I64d",&n,&m))
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%I64d",&an[i]);
        }
        sort(an,an+n);
        ll top = 1, i = 0;
        while(m > 0)
        {
            if(i < n && an[i] <= top)
            {
                top+=an[i];
                i++;
            }
            else
            {
                printf("%I64d ",top);
                top *= 2;
                m--;
            }
        }
        printf("\n");
    }
    return 0;
}