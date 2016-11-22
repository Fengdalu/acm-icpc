#include <iostream>
#include <cstdio>
#include <cstring>
#define LL long long
#define N 41
using namespace std;

LL f[N][N];
LL M, T, res;

void gen(LL f[N][N])
{
    memset(f, 0, sizeof f);
    f[1][0] = 1;
    for(int i = 2; i < N; i++) 
    { 
       f[i][0] = 1;
       for(int j = 1; j < i - 1; j++)
       f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
       f[i][i - 1] = 1;
    }
}

LL bit_count(LL x)
{
    int num = 0;
    while(x)
    {
        num += x & 1LL;
        x >>= 1LL;
    }
    return num;
}

LL offset(LL x)
{
   int num = 0;
   LL res = 1LL;
   while((res << 1LL) < x)
   {
       res <<= 1LL;
       num ++;
   }
   return num;
}

LL cal(LL p, LL r, LL T)
{
    if(T == 0 || p == 0) return 0;
    if(T == 1) return 1;

   if(p == 1) return (T == 1);
   if(p <= (1LL << (r - 2LL))) return cal(p, r - 1, T);
   else 
   {
       return cal(p - (1LL << (r - 2LL)), r - 1, T >> 1LL) + f[r - 1][offset(T) + 1];
   }
}

int main()
{ 
    gen(f);
    scanf("%I64d%I64d", &M, &T); 
    M++;
    if(bit_count(T) != 1) { puts("0"); return 0; }
    LL r = offset(M);
    LL c = offset(T) + 1;
    res = 0;
    for(int i = 1; i <= r; i++)
        res += f[i][c];
    LL add = 0;
    if(T == 1)
    { 
        if(r == 0) { puts("1"); return 0; }
        if((1LL << (r + 1)) - 1 == M) r++;
        printf("%I64d\n", r);
        return 0;
    }
    if((1LL << (r + 1)) - 1 == M) res += f[r + 1][c];
    else 
    {
        if(r == 0) r = 1;
        LL t = M - (1LL << r) + 1;
        add = cal(t, r + 1, T);
    }
    printf("%I64d\n", res + add);
    return 0;
}
