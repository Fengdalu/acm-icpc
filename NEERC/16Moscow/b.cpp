#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;
long long gcd(long long a,long long b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    long long l,r,w;
    scanf("%I64d%I64d%I64d",&l,&r,&w);
    if(w==r)
        puts("OK");
    else
    {
        if(r-gcd(w,r)>l-w)
            puts("DEADLOCK");
        else
            puts("OK");
    }
    return 0;
}
