#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long
#define PII pair<int, int>
#define AA first
#define BB second
typedef pair<PII, PII> obj;

obj f[12000];
LL sum;
int n;

LL calc(int x)
{
  LL sum = 0;
  for(int i = 0; i < n; i++)
  {
    if(x < f[i].AA.AA) continue;
    if(f[i].AA.AA + f[i].BB.AA <= x) sum += (LL)f[i].BB.AA * (LL)f[i].BB.BB;
    else
    {
      sum += (LL)f[i].BB.BB * (LL)(x - f[i].AA.AA);
    }
  }
  return sum;
}

int main()
{
  //freopen("input.txt", "r", stdin);
  int T; scanf("%d", &T);
  for(int cas = 1; cas <= T; cas++)
  {
    int R; scanf("%d", &R);
    scanf("%d", &n);
    sum = 0;
    for(int i = 0; i < n; i++) scanf("%d%d%d%d", &f[i].AA.AA, &f[i].AA.BB, &f[i].BB.AA, &f[i].BB.BB);
    for(int i = 0; i < n; i++) sum += (LL)f[i].BB.AA * (LL)f[i].BB.BB;
    sort(f, f + n);
    int l = f[0].AA.AA, r = R;
    while(l < r)
    {
      int mid = (l + r) / 2;
      LL s = calc(mid);
      if(2LL * s < sum) l = mid + 1; else r = mid;
    }
    bool flg = true;
    for(int i = 0; i < n; i++) if(f[i].AA.AA < l && l < f[i].AA.AA + f[i].BB.AA) { flg = false; }
    if(flg)
      for(int i = 0; i < n; i++)
      {
        if(f[i].AA.AA >= l)
        {
          l = f[i].AA.AA;
          break;
        }
      }
    if(l == f[n - 1].AA.AA + f[n - 1].BB.AA) l = R;
    printf("%d\n", l);
  }
}
