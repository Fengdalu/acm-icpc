#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1000010;
int prime[N];
bool check[N];
int f[10][N];
int F[N];
int tmp[10];
int tot;

void Eular()
{
    memset(check, 0, sizeof check);
    tot = 0;
	for (int i = 2; i < N; i++)
	{
		if (!check[i]) prime[tot++] = i;
		for (int j = 0; j < tot; j++)
		{
			if (i * prime[j] >= N) break;
			check[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}
int gg[20][20];
int gcd(int x, int y)
{
    return gg[x][y];
}
int GCD(int x, int y)
{
    if(y == 0) return x;
    return GCD(y, x % y);
}

void init()
{
    for(int i = 1; i <= 10; i++) for(int j = 1; j <= 10; j++)
        gg[i][j] = GCD(i, j);
}

int main()
{

    Eular();
    init();
    memset(F, 0, sizeof F);
    memset(f, 0, sizeof F);
    for(int i = 0; i < tot && prime[i] < N; i++)
    {
        int k = prime[i];
        while(k < N) { F[k]++; k += prime[i]; }
    }
    for(int i = 0; i < N; i++)
    f[F[i]][i]++;
    for(int j = 1; j < N; j++) for(int i = 0; i < 10; i++) f[i][j] += f[i][j - 1];

    int T; scanf("%d", &T);

    while(T--)
    {
        int l, r; scanf("%d%d", &l, &r);
        for(int i = 1; i < 10; i++) tmp[i] = f[i][r] - f[i][l - 1];
        int ans = 0;

        for(int i = 1; i < 10; i++) for(int j = 1; j < 10; j++)
        if(i == j && tmp[i] > 1)
            ans = max(ans, i);
        else if(i == j && tmp[i] == 1)
            ans = max(ans, 1);
        else if(tmp[i] && tmp[j])
            ans = max(ans, gcd(i, j));
        printf("%d\n", ans);
    }
    return 0;
}
