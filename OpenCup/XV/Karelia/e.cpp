#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <deque>
using namespace std;

const int maxn = 100020;
int n;
int a[maxn];
int ans[23][maxn];
bool vis[maxn];
int make(deque<int>q) {
    if(q.size() == 1) { ans[0][q.front()] = q.front(); return 0; }
    else if(q.size() == 2) {
        int x = q.front(); q.pop_front();
        int y = q.front(); q.pop_front();
        ans[0][x] = y;
        ans[0][y] = x;
        return 1;
    }
    else {
        int n = q.size() / 2;;
        deque<int>p;
        while(n--) {
            p.push_front(q.back());
            q.pop_back();
        }
        int l0 = q.front(), r0 = q.back(), l1 = p.front(), r1 = p.back();
        int k = max(make(q), make(p));
        ans[k][r0] = r1;
        ans[k][r1] = r0;
        return k + 1;
    }
    return -1;
}
int b[maxn], c[maxn];
int main() {
    freopen("permutation.in", "r", stdin);
    int t; scanf("%d", &t);
    srand(time(NULL));
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        /*
        n = 100000;
        for(int i = 1; i <= n; i++) a[i] = i;
        random_shuffle(a + 1, a + n + 1);
        */
        memset(vis, 0, sizeof (bool) * (n + 3));
        int tot = 1;
        for(int j = 0; j < 20; j++)
            memset(ans[j], -1, sizeof(int) * (n + 2));
        for(int i = 1; i <= n; i++)
        if(!vis[i]) {
            int k = i;
            deque<int>q;
            while(!vis[k]) {
                q.push_back(k);
                vis[k] = true;
                k = a[k];
            }
            if(q.size() == 1) ans[0][k] = k;
            else tot = max(tot, make(q));
        }
        printf("%d\n", tot);
        for(int i = 0; i < tot; i++) {
            for(int j = 1; j <= n; j++)
                if(ans[i][j] == -1) printf("%d ", j);
                else printf("%d ", ans[i][j]);
            printf("\n");
        }
    }
    return 0;
}
