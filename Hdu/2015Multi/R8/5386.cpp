#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
using namespace std;
#define MOD 258280327
#define LL long long
#define N 120
#define M 600

int s1[N][N];
int s2[N][N];
bool h[N], l[N];

int x[M], y[M], c[M];
int n, m;


namespace G
{
    const int MAXN = 600;
    const int MAXM = 600 * 600;
    int ind[MAXN];
    int t[MAXM], nt[MAXM];
    int in[MAXN];
    int q[MAXN];
    int cnt;
    int n;

    void init(int sz)
    {
        cnt = 0;
        for(int i = 1; i <= sz; i++) ind[i] = -1;
        for(int i = 1; i <= sz; i++) in[i] = 0;
        n = sz;
    }
    void add(int a, int b)
    {
        t[cnt] = b;
        nt[cnt] = ind[a];
        ind[a] = cnt;
        in[b]++;
        cnt++;
    }

    void top()
    {
        int l = 0, r = -1;
        for(int i = 1; i <= n; i++) if(in[i] == 0) {  q[++r] = i; }
        while(l <= r)
        {
            int x = q[l++];
            for(int k = ind[x]; k != -1; k = nt[k])
            {
                in[t[k]]--;
                if(in[t[k]] == 0) q[++r] = t[k];
            }
        }
    }
}

char tmp[10];
bool chk(int i, int j)
{
    if(c[i] == c[j] && x[i] != x[j]) return false;
    if(y[i] == y[j]) return false;
    else if(c[i] == c[j])
    {
//        cout << "CK " << i << " " << j << " " << s2[x[j]][1] << " " << y[x[j]] << endl;
        if(c[i])
        {
            if(!h[x[j]]) return false;
            else return s2[x[j]][1] == y[j];
        }
        else
        {
            if(!l[x[j]]) return false;
            else return s2[1][x[j]] == y[j];
        }
    }

    int X, Y;
    if(c[i]) { X = x[i]; Y = x[j]; }
    else { X = x[j]; Y = x[i]; }
    return s2[X][Y] == y[j];
}

int main()
{
//    freopen("input.txt", "r", stdin);
    int CASE; scanf("%d", &CASE);
    for(int T = 1; T <= CASE; T++)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) scanf("%d", &s1[i][j]);
        for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) scanf("%d", &s2[i][j]);

        for(int i = 1; i <= n; i++)
        {
            bool flg = true;
            for(int j = 1; j < n; j++) if(s2[i][j + 1] != s2[i][j]) flg = false;
            h[i] = flg;
        }

        for(int i = 1; i <= n; i++)
        {
            bool flg = true;
            for(int j = 1; j < n; j++) if(s2[j][i] != s2[j + 1][i]) flg = false;
            l[i] = flg;
        }

        for(int i = 1; i <= m; i++)
        {
            scanf("%s%d%d", tmp, &x[i], &y[i]);
            if(tmp[0] == 'H') c[i] = true;
            else c[i] = false;
        }

        G::init(m);
        for(int i = 1; i <= m; i++) for(int j = i + 1; j <= m; j++)
        {
            if(chk(i, j)) G::add(i, j);
            else if(chk(j, i)) G::add(j, i);
        }
        G::top();
        for(int i = 0; i < m; i++) if(i == 0) printf("%d", G::q[i]); else printf(" %d", G::q[i]);
        printf("\n");
    }
    return 0;
}
