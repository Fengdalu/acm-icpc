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
int q[maxn];
bool vis[maxn];
int f[maxn], g[maxn];
int main() {
    freopen("permutation.in", "r", stdin);
    int t; scanf("%d", &t);
    while(t--) {
        int n;
        bool flag = false;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        bool flag1 = true;
        for(int i = 1; i <= n; i++) if(a[i] != i) flag1 = false;
        if(flag1) {
            puts("0");
            continue;
        }
        memset(vis, 0, sizeof vis);
        for(int i = 1; i <= n; i++) g[i] = i;
        for(int i = 1; i <= n; i++) f[i] = i;
        for(int i = 1; i <= n; i++) if(!vis[i]) {
            int k = i, cnt = 0;
            while(!vis[k]) {
                vis[k] = true;
                q[cnt++] = k;
                k = a[k];
            }
            if(cnt == 1) f[q[0]] = q[0];
            if(cnt == 2) { f[q[0]] = q[1];  f[q[1]] = q[0]; }
            else if(cnt > 2) {
                flag = true;
                g[q[0]] = q[0];
                for(int i = 1; i <= cnt / 2; i++) {
                    g[q[i]] =  q[cnt - i];
                    g[q[cnt - i]] = q[i];
                    swap(q[i], q[cnt - i]);
                }
                for(int i = 0; i < cnt / 2; i += 1) {
                    f[q[i]] = q[cnt - i - 1];
                    f[q[cnt - i - 1]] = q[i];
                }
            }
        }
        if(flag) {
            puts("2");
            for(int i = 1; i <= n; i++) printf("%d ", f[i]);
            puts("");
            for(int i = 1; i <= n; i++) printf("%d ", g[i]);
            puts("");
        }
        else {
            puts("1");
            for(int i = 1; i <= n; i++) printf("%d ", f[i]);
            puts("");
        }
    }
    return 0;
}
