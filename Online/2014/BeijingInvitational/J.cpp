#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define FOR(i, n) for(int i = 0; i < n; i++)
#define AA first
#define BB second
#define PB(x) push_back(x)
#define SZ size()
#define MP(a, b) make_pair(a, b)
#define OP begin()
#define ED end()
#define CLR clear()
#define ULL unsigned long long
#define LL long long
typedef pair<int, int> PII;
#define N 300000
#define INF 0x3f3f3f

char A[N], B[N];
int f[N][100];
int s[N];
int lena, lenb;
int n, op;
namespace SA
{
    int len;
    int num[N];  //待处理的串
    int sa[N], rank[N], height[N];    // sa[1~n] value(0~n-1); rank[0..n-1] value(1..n); height[2..n]
    int wa[N], wb[N], wv[N], wd[N];

    int cmp(int *r, int a, int b, int x) {
        return r[a] == r[b] && r[a + x] == r[b + x];
    }

    void da(int *r, int n, int m) {       //  倍增算法 r为待匹配数组  n为总长度+1 m为字符范围
        int i, j, k, p, *x = wa, *y = wb, *t;
        for(i = 0; i < m; i++) wd[i] = 0;
     for(i = 0; i < n; i++) wd[x[i] = r[i]]++;
        for(i = 1; i < m; i++) wd[i] += wd[i - 1];
        for(i = n - 1; i >= 0; i--) sa[--wd[x[i]]] = i;
        for(j = 1, p = 1; p < n; j <<= 1, m = p) {
            for(p = 0, i = n - j; i < n; i++) y[p++] = i;
            for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
            for(i = 0; i < n; i++) wv[i] = x[y[i]];
            for(i = 0; i < m; i++) wd[i] = 0;
            for(i = 0; i < n; i++) wd[wv[i]]++;
            for(i = 1; i < m; i++) wd[i] += wd[i - 1];
            for(i = n - 1; i >= 0; i--) sa[--wd[wv[i]]] = y[i];
            for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++) {
                x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
            }
        }

        for(i = 0, k = 0; i < n; i++) rank[sa[i]] = i;
        for(i = 0; i < n - 1; height[rank[i++]] = k) {
            for(k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++);
        }
    }
}


int P2[30];
void init()
{
    P2[0] = 1;
    for(int i = 1; i <= 20; i++) P2[i] = P2[i - 1] * 2;
}


int RMQ(int l, int r)
{
    int k = log2(r - l + 1);
    return min(f[l][k], f[r - P2[k] + 1][k]);
}

bool check(int x)
{
    if(x + lenb > lena) return false;
    if(lenb > lena) return false;
    int cc = 0;
    int x1 = x, x2 = lena + 1;
    while(true)
    {
        int l = RMQ(min(SA::rank[x1], SA::rank[x2]) + 1, max(SA::rank[x1], SA::rank[x2]));

        x1 += l;
        x2 += l;
        if(x2 >= n) return true;
        cc++;
        if(cc > 2) return false;
        x1 += 1;
        x2 += 1;
        if(x2 >= n) return true;
        if(x1 >= lena) return false;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T; scanf("%d", &T);
    init();
    FOR(ii, T)
    {
        scanf("%s", A); lena = strlen(A);
        scanf("%s", B); lenb = strlen(B);

        FOR(i, lena) s[i] = A[i] - 'a' + 2; s[lena] = 1;
        FOR(i, lenb) s[i + lena + 1] = B[i] - 'a' + 2;
        n = lena + lenb + 1;
        s[n + 1] = 0;

        SA::da(s, n + 1, 30);

        for(int j = 0; j < 20; j++) for(int i = 0; i <= n; i++) if(i + (1 << (j + 1)) <= n) f[i][j] = INF; else break;
        for(int i = 1; i <= n; i++) f[i][0] = SA::height[i];
        for(int j = 0; j < 20; j++)
        {
            for(int i = 0; i <= n; i++)
                if(i + (1 << (j + 1)) <= n)
                {
                    f[i][j + 1] = min(f[i][j], f[i + (1 << j)][j]);
                }
                else break;
        }


        bool flg = false;
        for(int i = 0; i <= lena - lenb; i++)
        {
            if(check(i)) { printf("Case #%d: %d\n", ii + 1, i); flg = true; break; }
        }
        if(!flg) printf("Case #%d: %d\n", ii + 1, -1);
    }
	return 0;
}
