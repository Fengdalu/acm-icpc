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
#define SIZE 1000005
bool notprime[SIZE];
void getprime()
{
    notprime[1]=1;
    for(int i=2;i<SIZE;i++)
    {
        if(notprime[i])
            continue;
        for(int j=2*i;j<SIZE;j+=i)
            notprime[j]=1;
    }
}
int cool[1005];
int cnum;
bool check(int n)
{
    int n1=n;
    int n2=0;
    char str[11];
    int len=0;
    while(n)
    {
        str[len++]='0'+n%10;
        n/=10;
    }
    int head=0;
//    if(n1<14)
//        printf("%s\n",str);
    while(str[head]=='0')head++;
    for(int i=head;i<=len-1;i++)
        n2=n2*10+str[i]-'0';
//    if(n1<14)
//    printf("%d %d\n",n1,n2);
    if(n1!=n2&&!notprime[n1]&&!notprime[n2])
        return true;
    return false;
}
void init()
{
    cnum=1;
    for(int i=1;i<=1000000;i++)
    {
        if(check(i))
            cool[cnum++]=i;
        if(cnum==1001)
            break;
    }
}
int main()
{
    getprime();
    init();
    int t;
    scanf("%d",&t);

//    for(int i=1;i<=10;i++)
//        printf("%d\n",cool[i]);

    int ans=cool[t];
    if(ans==0)
        printf("-1\n");
    else
        printf("%d\n",ans);
    return 0;
}
