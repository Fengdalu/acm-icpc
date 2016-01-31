#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int Maxn = 500010;
int dp[Maxn][2];
int dp2[Maxn][2];
pair<int, int> pre[Maxn][2], pre2[Maxn][2];

vector<int>g[Maxn];
vector<char>s[Maxn];
int father[Maxn];
char str[Maxn];
char buf[5];
int n, L;

void dfs(int x) {
    for(int i = 0; i < g[x].size(); i++)
    if(g[x][i] != father[x]) {
        father[g[x][i]] = x;
        dfs(g[x][i]);
    }
}

void dfs1(int x) {
    for(int i = 0; i < g[x].size(); i++)
    if(g[x][i] != father[x]) dfs1(g[x][i]);

    int from1 = 0, from2 = 0;
    int type1 = 0, type2 = 0;
    dp[x][0] = dp[x][1] = 0;
    int add1 = 0, add2 = 0;
    for(int i = 0; i < g[x].size(); i++)
    if(g[x][i] != father[x]) {
        int v = g[x][i];
//        cout << dp[v][0] + (int)(str[dp[v][0] + 1] == s[x][i]) << " ";
        if(dp[v][0] + (int)(str[dp[v][0] + 1] == s[x][i]) > dp[from1][type1] + add1) {
            swap(from1, from2);
            swap(add1, add2);
            swap(type1, type2);
            from1 = v;
            add1 = (str[dp[v][0] + 1] == s[x][i]);
            type1 = 0;
        }
        else if(dp[v][0] + (int)(str[dp[v][0] + 1] == s[x][i]) > dp[from2][type2] + add2) {
            from2 = v;
            add2 = (str[dp[v][0] + 1] == s[x][i]);
            type2 = 0;
        }
    }
//    cout << "X " << x << " " << from1 << " " << from2 << endl;
    /*
    for(int i = 0; i < g[x].size(); i++)
    if(g[x][i] != father[x]) {
        int v = g[x][i];
        if(dp[v][1] + (int)(str[dp[v][1] + 1] == s[x][i]) > dp[from1][type1] + add1) {
            from1 = v;
            add1 = (str[dp[v][1] + 1] == s[x][i]);
            type1 = 1;
        }
        else if(dp[v][1] + (int)(str[dp[v][1] + 1] == s[x][i]) > dp[from2][type2] + add2) {
            from2 = v;
            add2 = (str[dp[v][1] + 1] == s[x][i]);
            type2 = 1;
        }
    }
    */
    if(from1 != 0)
        dp[x][0] = dp[from1][type1] + add1;
    if(from2 != 0)
        dp[x][1] = dp[from2][type2] + add2;
    if(from1 != 0)
        pre[x][0] = make_pair(from1, type1);
    if(from2 != 0)
        pre[x][1] = make_pair(from2, type2);
}

int find(pair<int, int> pre[Maxn][2], int x, int mask) {
    if(pre[x][mask].first == 0) return x;
    else return find(pre, pre[x][mask].first, pre[x][mask].second);
}

int main() {
//    freopen("d:/F.in", "r", stdin);
    scanf("%d%d", &n, &L);
//    printf("%d %d\n",n,L);
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d%d%s", &x, &y, buf);
        g[x].push_back(y);
        g[y].push_back(x);
        s[x].push_back(buf[0]);
        s[y].push_back(buf[0]);
    }
    scanf("%s", str + 1);
    str[L + 1] = '#';
    memset(dp, 0, sizeof dp);
    dfs(1);
    dfs1(1);
    swap(dp, dp2);
    swap(pre, pre2);

    reverse(str + 1, str + L + 1);
    dfs1(1);
    swap(dp, dp2);
    swap(pre, pre2);
//    for(int i = 1; i <= n; i++) cout << father[i] << " "; cout << endl;
//    for(int i = 1; i <= n; i++) cout << i << " " << dp[i][0] << " " << dp[i][1] << " " << pre[i][0].first << " "<< pre[i][0].second << endl;
//    cout << endl;
//    for(int i = 1; i <= n; i++) cout << i <<" " << dp2[i][0] << " " << dp2[i][1] << endl;
//    cout << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
            if(pre[i][j].first != pre2[i][k].first) {
                if(dp[i][j] + dp2[i][k] >= L) {
                    //cout <<i <<endl;
                    int x = find(pre, i, j), y = find(pre2, i, k);
                    printf("%d %d\n", x, y);
                    return 0;
                }
            }
    }
    puts("-1 -1");
    return 0;
}