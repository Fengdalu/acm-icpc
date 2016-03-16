#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
using namespace std;

const int Maxn = 100010;
map<long long, int>base;
typedef map<long long, int>::iterator mit;
struct node{
    long long l, r, h;
    long long v;
    node() {}
    node(long long l, long long r, long long h, long long v)
    : l(l), r(r), h(h), v(v) {}
}line[Maxn * 2];

int w, h, n, m;
int a[Maxn], b[Maxn], x[Maxn], y[Maxn];
long long ans = 0;

int cmp(node p, node q) {
    if(p.h == q.h) return p.v < q.v;
    return p.h > q.h;
}

long long cal(long long l, long long r) {
    return max(0LL, (r - l) - (long long)m + 1LL);
}

void run() {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        line[cnt++] = node(x[i], a[i] + 1, y[i], -1);
        line[cnt++] = node(x[i], a[i] + 1, b[i] + 1, 1);
    }
    line[cnt++] = node(1, w + 1, 1, -1);
    sort(line, line + cnt, cmp);
    
    base.clear();
    base[1] = 2;
    base[w + 1] = 2;
    long long tot = cal(1, w + 1);
    long long pre = h + 1;
    for(int i = 0; i < cnt; i++) {
        if(line[i].v > 0) {
            mit l = base.lower_bound(line[i].l);
            mit r = base.lower_bound(line[i].r);
            while(l->first > line[i].l) l--;
            long long a = l->first;
            long long b = r->first;
            if(!(i - 1 >= 0 && line[i - 1].h == line[i].h && line[i].v == line[i - 1].v))
                ans += (pre - line[i].h) * tot;
            tot = tot - cal(a, b) + cal(a, line[i].l) + cal(line[i].r, b);
            base[line[i].l]++;
            base[line[i].r]++;
        }
        else {
            if(!(i - 1 >= 0 && line[i - 1].h == line[i].h && line[i].v == line[i - 1].v))
                ans += (pre - line[i].h) * tot;
            mit it;
            it = base.find(line[i].l);
            if(it->second == 1) {
                base.erase(it);
            }
            else it->second--;
            it = base.find(line[i].r);
            if(it->second == 1) {
                base.erase(it);
            }
            else it->second--;
            
            mit l = base.lower_bound(line[i].l);
            mit r = base.lower_bound(line[i].r);
            while(l->first > line[i].l) l--;
            long long a = l->first;
            long long b = r->first;
            tot = tot + cal(a, b) - cal(a, line[i].l) - cal(line[i].r, b);
        }
        pre = line[i].h;
    }
}

int main() {
    while(~scanf("%d%d%d%d", &w, &h, &n, &m)) {
        int cnt = 0;
        ans = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d%d%d%d", &x[i], &y[i], &a[i], &b[i]);
        }
        run();
        swap(w, h);
        swap(x, y);
        swap(a, b);
        run();
        if(m == 1) ans /= 2LL;
        printf("%lld\n", ans);
    }
    return 0;
}