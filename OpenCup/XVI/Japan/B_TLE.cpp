#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <cstring>
#include <map>

const int maxn = 3010;
int x[maxn], y[maxn], d[maxn];
char buf[10];
int h[maxn];
int n;
int dir['z'];
std::set< std::pair<int, int> >f[maxn], g[maxn];
typedef std::set< std::pair<int, int> >::iterator pit;

int main() {
    //freopen("B1.in", "r", stdin);
    dir['<'] = 0;
    dir['v'] = 1;
    dir['>'] = 2;
    dir['^'] = 3;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d%s", &x[i], &y[i], buf);
        d[i] = dir[buf[0]];
    }
    int cnt;
    for(int i = 0; i < n; i++) h[i] = x[i];
    std::sort(h, h + n);
    cnt = std::unique(h, h + n) - h;
    for(int i = 0; i < n; i++) x[i] = std::lower_bound(h, h + cnt, x[i]) - h;
    for(int i = 0; i < n; i++) h[i] = y[i];
    std::sort(h, h + n);
    cnt = std::unique(h, h + n) - h;
    for(int i = 0; i < n; i++) y[i] = std::lower_bound(h, h + cnt, y[i]) - h;

    int ans = 0;
    for(int p = 0; p < n; p++) {
        for(int i = 0; i < n; i++) {
            f[i].clear();
            g[i].clear();
        }
        int tot = 0;
        for(int i = 0; i < n; i++) {
            f[x[i]].insert(std::make_pair(y[i], d[i]));
            g[y[i]].insert(std::make_pair(x[i], d[i]));
        }
        int a = x[p];
        int b = y[p];
        while(true) {
            pit ix = f[a].lower_bound(std::make_pair(b, -1)), eix = ix;
            pit iy = g[b].lower_bound(std::make_pair(a, -1)), eiy = iy;
            int ap = a, bp = b;
            //std::cout << a << " " << b << std::endl;
            int c = ix->second;
            tot++;
            if(c == 0 || c == 2) {
                if(c == 0 && iy == g[b].begin()) break;
                if(c == 0) iy--;
                else iy++;
                if(iy == g[b].end()) break;
                a = iy->first;
                f[ap].erase(eix);
                g[bp].erase(eiy);
            }
            else if(c == 1 || c == 3) {
                if(c == 3 && ix == f[a].begin()) break;
                if(c == 3) ix--;
                else ix++;
                if(ix == f[a].end()) break;
                b = ix->first;
                f[ap].erase(eix);
                g[bp].erase(eiy);
            }
        }
        //std::cout << std::endl;
        ans = std::max(ans, tot);
    }
    printf("%d\n", ans);
    return 0;
}
