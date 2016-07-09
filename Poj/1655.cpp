#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 20100;
const int maxm = 2 * maxn;
#define mp(x, y) make_pair(x, y)

typedef pair<int, int> obj;
int ind[maxn];
int son[maxn];
int nt[maxm], to[maxm];
int cnt;

void add(int x, int y) {
    to[cnt] = y;
    nt[cnt] = ind[x];
    ind[x] = cnt++;
}

obj dfs(int x, int fa, int n) {
    int tmp = 0;
    obj ans(n + 1, -1);
    for(int k = ind[x]; k != -1; k = nt[k]) {
        int v = to[k];
        if(v != fa) {
            obj t = dfs(v, x, n);
            if(t.first < ans.first || (t.first == ans.first && t.second < ans.second))
                ans = t;
            tmp = max(tmp, son[v]);
            son[x] += son[v];
        }
    }
    son[x]++;
    tmp = max(tmp, n - son[x]);
    if(tmp < ans.first || (tmp == ans.first && x < ans.second))
        ans = mp(tmp, x);
    return ans;
}

int main() {
    int _;
    scanf("%d", &_);
    while(_--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) ind[i] = -1;
        for(int i = 0; i < n; i++) son[i] = 0;
        cnt = 0;
        for(int i = 0; i < n - 1; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            x--; y--;
            add(x, y); add(y, x);
        }
        obj t = dfs(0, -1, n);
        printf("%d %d\n", 1 + t.second, t.first);
    }
    return 0;
}
