#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define PB(x) push_back(x)
#define SZ size()
#define PII pair<int, int>
#define AA first
#define BB second

vector<int>G[52];
vector<PII>ans;
int T[52][20000];
map<char, int>H;
int MaxT[52];
int n, dst;

int dfs(int x, int t)
{
    if(x != dst && G[x].SZ == 0) return false;
    MaxT[x] = max(t, MaxT[x]);
    if(x == dst) return true;
    if(dfs(G[x][0], t + 1)) T[x][t] = 0;
    else if(dfs(G[x][1], t + 1)) T[x][t] = 1;
    else return false;

    return true;
}

int main()
{
    freopen("instruction.in", "r", stdin);
    freopen("instruction.out", "w", stdout);

    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        char buf[3]; scanf("%s", buf);
        if(buf[0] == 's') { int x; scanf("%d", &x); G[x].PB(i); }
        else { int x; scanf("%d", &x); G[x].PB(i); scanf("%s", buf); H[buf[0]] = i; }
    }
    memset(T, -1, sizeof T);
    memset(MaxT, 0, sizeof MaxT);

    int m; scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        int t; scanf("%d", &t); char buf[3]; scanf("%s", buf); dst = H[buf[0]];
        dfs(0, t);
    }
    //for(int i = 1; i <= n; i++) cout << MaxT[i] << " "; cout << endl;
    for(int i = 1; i <= n; i++)
    {
        int p = 0;
        for(int j = 0; j <= MaxT[i]; j++)
        if(T[i][j] != -1) if(p != T[i][j])
        {
            ans.PB(PII(j, i));
            p = T[i][j];
        }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.SZ);
    for(int i = 0; i < ans.SZ; i++) printf("%d %d\n", ans[i].BB, ans[i].AA);
    fclose(stdout);
    return 0;
}
