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
    /*
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j <= i; j++)
            printf("%5I64d", f[i][j]);
        putchar('\n');
    }
    */
}

LL bit_count(LL x)
{
    int num = 0;
    while(x)
    {
        num += x & 1;
        x >>= 1;
    }
    return num;
}
LL offset(LL x)
{
   int num = 0;
   LL res = 1;
   while((res << 1) < x)
   {
       res <<= 1;
       num ++;
   }
   return num;
}

LL cal(LL p, LL r, LL T)
{
   cout << "p: " << p << " r: " << r << " T: "  << T << endl;
   if(p == 1) return (T == 1);
   if(p <= (1LL << (r - 1LL))) return cal(p, r - 1, T);
   else 
   {
       //cout << offset(T) << " " << f[r - 1][offset(T) + 1] << endl;
       cout << (1LL << (r - 1LL)) << endl;
       return cal(p - (1LL << (r - 1LL)), r - 1, T >> 1) + f[r - 1][offset(T) + 1];
   }
}

int main()
{ 
    gen(f);
    scanf("%I64d%I64d", &M, &T); 
    if(bit_count(T) != 1) { puts("0"); return 0; }
    LL r = offset(M);
    LL c = offset(T);
    res = 0;
    cout << r << " " << c << endl;
    for(int i = 1; i < r - 1; i++)
        res += f[i][c];
    LL add = 0;
    if((1 << (r + 1)) - 1 == M) res += f[r][c];
    else 
    {
        LL t = M - (1LL << r) + 1;
        LL p = (1LL << r) + 1;
        cout << t << " " << r << endl;
        add = cal(t, r + 1, T);
    }
    printf("%I64d\n", res + add);
    return 0;
}
