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
    f[0][0] = 1;
    for(int i = 1; i < N; i++) 
    { 
       f[i][0] = 1;
       for(int j = 1; j < N; j++)
       f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
       f[i][i] = 1;
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
   while(res <= x)
   {
       res <<= 1;
       num ++;
   }
   return num;
}

LL cal(int p, int r, int T)
{
   //cout << "p: " << p << " r: " << r << " T: "  << T << endl;
   if(p == 1) return (T == 1);
   if(p <= 1 << (r - 1)) return cal(p, r - 1, T);
   else 
   { 
      // cout << r - 1 << " " << f[r - 1][offset(T) - 1] << endl; 
      return f[r - 1][offset(T) - 1] + cal(p - (1 << (r - 1)), r - 1, T >> 1);
   }
}

int main()
{ 
    gen(f);
    scanf("%I64d%I64d", &M, &T); 
    if(bit_count(T) != 1) { puts("0"); return 0; }
    LL r = offset(M);
    LL c = offset(T) - 1;
    res = 0;
    cout << r << " " << c << endl;
    for(int i = 1; i < r - 1; i++)
        res += f[i][c];
    LL add;
    if(1 << (r - 1) == M) res += f[r][c];
    else 
    {
        int t = M - (1 << (r - 1));
        add = cal(t, r - 1, T);
        //cout << add << endl;
    }
    printf("%I64d\n", res + add);
    return 0;
}
