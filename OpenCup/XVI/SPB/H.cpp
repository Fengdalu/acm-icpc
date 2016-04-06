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
#define eps 1e-8

long long check(long long n)
{
    for(long long i=1LL;;i++)
    {
        if(n<(i+1LL))
            return n;
        if(n%(i+1LL)==0)
            return -1LL;
        n=(n/(i+1LL))*i+n%(i+1LL);
    }
}
int main()
{
    freopen("sieve.in","r",stdin);
    freopen("sieve.out","w",stdout);
    int n;
    //scanf("%d",&n);
//
//    for(long long i=1;i<=100000000LL;i++)
//    {
//        if(check(i)!=-1LL)
//            printf("%I64d %I64d\n",i,check(i));
//    }
    cin >> n;
    while(n--)
    {
        long long num;
        cin >> num;
        cout << check(num) << endl;
//        scanf("%I64d",&num);
//        printf("%I64d\n",check(num));
    }
    return 0;
}
