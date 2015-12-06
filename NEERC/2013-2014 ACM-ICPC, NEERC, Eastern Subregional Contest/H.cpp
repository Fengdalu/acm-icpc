#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=1010;
const int MAXM=MAXN * MAXN;

int uN, vN;
int linker[MAXN];
bool used[MAXN];
int ind[MAXN];
int t[MAXM], nt[MAXM];
int c[MAXN], v[MAXN];
int a, b, cnt;
int n;


bool dfs(int u)
{
    int v;
    for(int k = ind[u]; k != -1; k = nt[k])
    {
        int v = t[k];
        if(!used[v])
        {
            used[v] = true;
            if(linker[v] == -1 || dfs(linker[v]))
            {
                linker[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hungary()
{
    int res = 0;
    int u;
    memset(linker, -1, sizeof(linker));
    for(u = 0; u < n; u++)
    {
        memset(used, 0, sizeof(used));
        if(dfs(u)) res++;
    }
    return res;
}

void add(int a, int b) {
    t[cnt] = b;
    nt[cnt] = ind[a];
    ind[a] = cnt++;
}

int main() {
    scanf("%d%d", &a, &b);
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d%d", &c[i], &v[i]);
    memset(ind, -1, sizeof ind);
    cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        if(v[i] == 0 && v[j] == 1) if(c[i] < c[j]) if(c[j] - c[i] >= a || c[j] - c[i] <= b)
            add(i, j);
    if(hungary() == n / 2) {
        puts("No reason");
        for(int i = 0; i < n; i++) if(linker[i] != -1) {
            printf("%d %d\n", c[linker[i]], c[i]);
        }
    }
    else puts("Liar");
    return 0;
}