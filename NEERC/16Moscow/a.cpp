#include <bits/stdc++.h>

const int N = 3e5+10;
const int inf = 1e9;

struct BIT {
    int _[N+10];
    int lowbit(int x) { return x & (-x); }
    void init() {
        memset(_, 0, sizeof _);
    }
    void insert(int l, int c) {
        while(l < N) {
            _[l] = std::max(_[l], c);
            l += lowbit(l);
        }
    }
    int cal(int l) {
        int tot = 0;
        while(l) {
            tot = std::max(tot, _[l]);
            l -= lowbit(l) ;
        }
        return tot;
    }
} c;

struct BIT2 {
    int _[N+10];
    int lowbit(int x) { return x & (-x); }
    void init() {
        memset(_, 0x3f, sizeof _);
    }
    void insert(int l, int c) {
        while(l < N) {
            _[l] = std::min(_[l], c);
            l += lowbit(l);
        }
    }
    int cal(int l) {
        int tot = inf;
        while(l) {
            tot = std::min(tot, _[l]);
            l -= lowbit(l) ;
        }
        return tot;
    }
} c1;


int a[N];
int l[N], r[N];
int n;

void out(int x) {
    if(x <= n) printf("%d", x);
    else if(n < x && x <= 2 * n) printf("%d", x - n);
    else printf("%d", x - 2 * n);
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    c.init();
    std::vector<int> index(n);
    for(int i = 0; i < n; i++) index[i] = a[i + 1];
    std::sort(index.begin(), index.end());
    for(int i = 1; i <= n; i++) a[i] = std::lower_bound(index.begin(), index.end(), a[i]) - index.begin() + 1;
    for(int i = 1; i <= n; i++) a[i + n] = a[i];
    for(int i = 1; i <= n; i++) a[i + n + n] = a[i];
    for(int i = 1; i <= n + n + n; i++) {
        l[i] = c.cal(a[i] - 1);
        c.insert(a[i], i);
    }
    int ed = n + n + n + 1;
    c1.init();
    for(int i = n + n + n; i >= 1; i--) {
        r[i] = c1.cal(a[i] - 1);
        c1.insert(a[i], i);
    }
    int ans = 3 * n;
    int x, y, z;
    /*
    for(int i = 1; i <= n * 3; i++) printf("%d ", l[i]); puts("");
    for(int i = 1; i <= n * 3; i++) printf("%d ", r[i]); puts("");
    */
    for(int i = 1; i <= n * 3; i++) {
        if(1 <= l[i] && l[i] < i && i < r[i] && r[i] <= 3 * n) {
            //printf("%d %d\n", l[i], r[i]);
            int t =  i - l[i] + r[i] - i;
            if(t < ans) {
                x = l[i]; y = i; z = r[i];
                ans = t;
            }
        }
    }
    out(x); printf(" "); out(y); printf(" "); out(z);
    return 0;
}

