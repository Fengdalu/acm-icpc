#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100010;
const int maxm = 200010;
int n, m;
int ind[maxn], col[maxn];
int to[maxm], nt[maxm];
int cnt;
void add(int a, int b) {
    to[cnt] = b;
    nt[cnt] = ind[a];
    ind[a] = cnt++;
}

bool dfs(int x) {
    if(col[x] == -1) col[x] = 0;
    for(int k = ind[x]; k != -1; k = nt[k]) {
        int v = to[k];
        if(col[v] == -1) {
            col[v] = col[x] ^ 1;
            if(!dfs(v)) return false;
        }
        if(col[v] == col[x]) return false;
    }
    return true;
}

int main() {
    int n, m;
    memset(ind, -1, sizeof ind);
    scanf("%d%d", &n, &m);
    while(m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--; b--;
        add(a, b);
        add(b, a);
    }
    memset(col, -1, sizeof col);
    bool flag = true;
    for(int i = 0; i < n; i++)
    if(col[i] == -1) flag &= dfs(i);
    if(!flag) {
        puts("-1");
    }
    else {
        int nx = 0;
        for(int i = 0; i < n; i++)
        if(col[i] == 0) nx++;
        printf("%d\n", nx);
        for(int i = 0; i < n; i++)
        if(col[i] == 0) printf("%d ", i + 1);
        puts("");
        printf("%d\n", n - nx);
        for(int i = 0; i < n; i++)
        if(col[i] == 1) printf("%d ", i + 1);
    }
    return 0;
}
