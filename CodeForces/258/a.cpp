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
#define LL long long
#define pii pair<int,int>

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int ans=min(a,b);
    if(ans&1)puts("Akshat");
    else puts("Malvika");
    return 0;
}
