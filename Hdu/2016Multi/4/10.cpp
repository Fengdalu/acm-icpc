#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100010;
const int maxm = 6e6;
int a[maxn];
int mx[maxm], add[maxm];
const int aa = -2e5, bb = 1e6 + 5;

void update(int u) {
    mx[u] = max(mx[u << 1], mx[u << 1 | 1]);
}

void down(int u) {
    if(!add[u]) return;
    add[u << 1]  += add[u];
    add[u << 1 | 1] += add[u];
    mx[u << 1] += add[u];
    mx[u << 1 | 1] += add[u];
    add[u] = 0;
}

void build(int u, int l, int r) {
    add[u] = 0;
    mx[u] = 0;
    if(l == r) {
        return ;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1, mid + 1, r);
}

void upd(int u, int l, int r, int p, int w) {
    if(l == r) {
        mx[u] = max(mx[u], w);
        return;
    }
    down(u);
    int mid = (l + r) >> 1;
    if(p <= mid) upd(u << 1, l, mid, p, w);
    else upd(u << 1 | 1, mid + 1, r, p, w);
    update(u);
}



void update(int u, int l, int r, int a, int b) {
    if(a <= l && r <= b) {
        mx[u] += 1;
        add[u] += 1;
        return;
    }
    int mid = (l + r) >> 1;
    down(u);
    if(b <= mid) update(u << 1, l, mid, a, b);
    else if(a > mid) update(u << 1 | 1, mid + 1, r, a, b);
    else {
        update(u << 1, l, mid, a, b) ;
        update(u << 1 | 1, mid + 1, r, a, b) ;
    }
    update(u);
}

int cal(int u, int l, int r, int a, int b) {
    if(a <= l && r <= b) return mx[u];
    int mid = (l + r) >> 1;
    down(u);
    if(b <= mid) return cal(u << 1, l, mid, a, b);
    else if(a > mid) return cal(u << 1 | 1, mid + 1, r, a, b);
    return max(cal(u << 1, l, mid, a, b), cal(u << 1 | 1, mid + 1, r, a, b));
}

int main() {
    int _T, cas = 1; scanf("%d", &_T);
    while(_T--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        memset(add, 0, sizeof add);
        memset(mx, 0, sizeof mx);
        build(1, aa, bb);
        int ans = 0;
        int l = 0;
        for(int i = 0; i < n; i++) {
            if(a[i])  {
                int f = 1 + cal(1, aa, bb, aa, l + a[i] - 1);
                ans = max(ans, f);
                upd(1, aa, bb, l + a[i], f);
            }
            else {
                ans++;
                l --;
                update(1, aa, bb, l - 1e5, l + 1e6);
            }
        }
        printf("Case #%d: %d\n", cas++, ans);
    }
    return 0;
}
