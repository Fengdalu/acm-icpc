#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 5

using namespace std;

const int MOD = 10000;

struct Matrix
{
    int n, m;
    int c[N * N];
    Matrix(){}
    Matrix(int n, int m)
    {
        memset(c, 0, sizeof c);
       this->n = n; 
       this->m = m;
    }
    int get(int x, int y)
    {
        return c[x * n + y];
    }
    void add(int x, int y, int cc)
    {
        c[x * n + y] += cc;
        c[x * n + y] %= MOD;
    }
    Matrix& set(int x, int y, int cc)
    {
       c[x * n + y] = cc;
       return *this;
    }
    Matrix& operator *(Matrix& b)
    {
       static Matrix ans(2, 2);
       memset(ans.c, 0, sizeof ans.c);
       for(int i = 0; i < n; i++) 
           for(int j = 0; j < m; j++)
           if(get(i, j))
            for(int k = 0; k < b.m; k++)
                  ans.add(i, k, get(i, j) * b.get(j, k) % MOD);
       return ans;
    }
}; 
Matrix& pow(Matrix& x, int c)
{
    static Matrix ans(2, 2);
    memset(ans.c, 0, sizeof ans.c);
    ans.set(0, 0, 1).set(1, 1, 1);
    while(c)
    {
        if(c & 1) ans = ans * x;
        x = x * x;
        c >>= 1;
    }
    return ans;
}

int main()
{
    Matrix a(2, 2), x(4, 1), y(4, 1);
    a.set(0, 0, 1).set(0, 1, 1).set(1, 0, 1).set(1, 1, 0); 
    int n;
    while(true)
    {
        scanf("%d", &n);
        if(n == -1) break;
        memset(a.c, 0, sizeof a.c);
        a.set(0, 0, 1).set(0, 1, 1).set(1, 0, 1).set(1, 1, 0); 
        printf("%d\n", pow(a, n).get(1, 0));
    }
    return 0;
}
