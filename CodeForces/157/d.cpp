#include <iostream>
#include <cstdio>
#include <cstring>
#define LL long long
using namespace std;
const LL MOD = 1000000007;


LL f[10];
LL a[10][10];
LL n, m;
char s[100];

LL pow(LL x, LL k)
{
    LL ans = 1LL;
    while(k)      
    {
        if(k & 1) ans = ans * x % MOD;
        x = x * x % MOD;
        k >>= 1;
    }
    return ans;
}

LL C(LL n, LL k)
{
    if(n < 0 || k < 0 || k > n) return 0;
    LL ans = 1;
    for(LL i = n; i > n - k; i--)  
        ans = ans * i;
    while(k) { ans /= k; k--;}
    return ans % MOD;
}

void cala()
{
    memset(a, 0, sizeof a);
    a[1][1] = 2;
    a[1][0] = 7;
    for(LL i = 2; i <= 10; i++)
    {
        a[i][0] = 7LL * pow(8, i - 1);
        for(LL j = 1; j < i; j++)
        {
            if(i != j)
            a[i][j] = (
                2LL * pow(8, i - j) % MOD
                * C(i - 1, j - 1) % MOD
                * pow(2, j - 1) % MOD 
                + 7LL * pow(8, i - j - 1) % MOD
                * C(i - 1, j) % MOD
                * pow(2, j) % MOD
            ) % MOD;
            else 
                a[i][j] = pow(2, j);
        }
    }
}

void calf()
{
   n = strlen(s);
   for(LL int i = 0; i < n; i++)
   {
      int tot = 0; 
      for(LL j = 0; j < n; j++)
      {  
          
      }
   }
}

int main()
{
    cala();
    scanf("%s", s);
    
}
