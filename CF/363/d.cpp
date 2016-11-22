#include <bits/stdc++.h>
using namespace std;

const int maxn = 200100;
int fa[maxn];
int p[maxn];
int vis[maxn];
int n;

int find(int x) { if(fa[x] == x) return x; return fa[x] = find(fa[x]); }

int main() {
    scanf("%d", &n);
    memset(vis, 0, sizeof vis);
    int ans = 0;
    for(int i = 1; i <= n; i++) scanf("%d", &p[i]);
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= n; i++) {
        int a = find(i), b = find(p[i]);
        if(a != b) {
            fa[find(i)] = find(p[i]);
        }
        else if(p[i] != i){
            vis[i] = true;
            ans++;
        }
    }
    int tot = 0;
    for(int i = 1; i <= n; i++) if(!vis[i] && find(i) == i) tot++;
    if(tot > 1) {
        printf("%d\n", ans + tot - 1);

        int i = 1, j = 1;
        while((vis[i] || find(i) != i) && i <= n) i++;
        while(j <= n && !vis[j]) j++;
        int rt;
        if(i == n + 1) {
            p[j] = j;
            rt = j;
        }
        else rt = i;
        i = 1;
        while(i <= n) {
            if(vis[i] || find(i) == i) {
                p[i] = rt;
            }
            i++;
        }
        for(int i = 1; i <= n; i++) printf("%d ", p[i]);
    }
    else {
        int i = 1, j = 1;
        while((vis[i] || find(i) != i) && i <= n) i++;
        while(j <= n && !vis[j]) j++;
        int rt;
        if(i == n + 1) {
            p[j] = j;
            rt = j;
        }
        else rt = i;
        for(int i = 1; i <= n; i++) if(vis[i]) p[i] = rt;
        printf("%d\n", ans);
        for(int i = 1; i <= n; i++) printf("%d ", p[i]);
    }
}
