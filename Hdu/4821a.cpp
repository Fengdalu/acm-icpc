#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<cstdlib>
#include<queue>
#include<stack>
#include<vector>
#include<ctype.h>
#include<algorithm>
#include<string>
#define PI acos(-1.0)
#define maxn 10005
#define INF 0x7fffffff
#define SEED 31
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;
map < ULL , int > P;
ULL Hash[100005];
ULL K[100005];
int main()
{
freopen("input.in", "r", stdin);
  int M,L;
  char ss[100005];
  while(scanf("%d%d",&M,&L)!=EOF)
  {
    ULL tt=1;
    scanf("%s",ss);
    int len=strlen(ss);
    ULL res=0;
    Hash[len]=0;
    K[0]=1;
    for(int i=1; i<=L; i++)
      K[i]=K[i-1]*SEED;
    for(int i=len-1; i>=0; i--)
    {
      Hash[i]=Hash[i+1]*SEED+(ss[i]-'a'+1);
    }
     for(int i = 0; i <= 100; i++) cout << Hash[i] << " "; cout <<endl;
    int t=0,aa=0;
    for(int i=0; i<L&&i+M*L<len; i++)
    {
      P.clear();
      for(int j=i; j<M*L+i; j+=L)
      {
        P[Hash[j]-Hash[j+L]*K[L]]++;
      }
      if(P.size()==M)
        aa++;
    cout << len << endl;
      for(int j=M*L+i; j<=len-L; j+=L)
      {
        int head= j-M*L;
        P[Hash[head]-Hash[head+L]*K[L]]--;
        if(P[Hash[head]-Hash[head+L]*K[L]]==0)
          P.erase(Hash[head]-Hash[head+L]*K[L]);
        P[Hash[j]-Hash[j+L]*K[L]]++;
        if(P.size()==M) aa++;
      }
    }
    printf("%d\n",aa);
  }
  return 0;
}
