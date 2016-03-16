#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

const int Mod = 10007;
const int maxn = 400010;
int n, m;

struct tree {
    struct node {
        int l, r;
        int sum1;
        int sum2;
        int sum3;
        int mul;
        int add;
        int set;
    }f[maxn];
    int root;
    int cnt;

    int build(int l, int r) {
        int x = cnt++;
        f[x].sum1 = f[x].sum2 = f[x].sum3 = f[x].add = 0;
        f[x].set = -1;
        f[x].mul = 1;
        if(l < r) {
            int mid = (l + r) / 2;
            f[x].l = build(l, mid);
            f[x].r = build(mid + 1, r);
        }
        return x;
    }

    void init(int l, int r) {
        cnt = 0;
        root = build(l, r);
    }
    tree() {
        cnt = 0;
        root = 0;
    }

    void add(int x, int l, int r, int c) {
        if(!c) return;
        int L = (r - l + 1);
        f[x].sum3 = (f[x].sum3 + (3 * f[x].sum2 % Mod * c) % Mod + (3 * f[x].sum1 * c % Mod * c) % Mod + L * c % Mod * c % Mod * c % Mod) % Mod;
        f[x].sum2 = (f[x].sum2 + (2 * f[x].sum1 % Mod * c) % Mod + (L * c % Mod * c) % Mod) % Mod;
        f[x].sum1 = (f[x].sum1 + L * c % Mod) % Mod;
        f[x].add += c;
        f[x].add %= Mod;
    }

    void set(int x, int l, int r, int v) {
        if(v == -1) return;
        int L = (r - l + 1);
        f[x].add = 0;
        f[x].mul = 1;
        f[x].sum1 = v * L % Mod;
        f[x].sum2 = v * v % Mod * L % Mod;
        f[x].sum3 = v * v % Mod * v % Mod * L % Mod;
        f[x].set = v;
    }

    void mul(int x, int l, int r, int v) {
        if(v == 1) return;
        f[x].sum1 = (f[x].sum1 * v) % Mod;
        f[x].sum2 = (f[x].sum2 * v % Mod * v) % Mod;
        f[x].sum3 = (f[x].sum3 * v % Mod * v % Mod * v) % Mod;
        f[x].add = (f[x].add * v) % Mod;
        f[x].mul = (f[x].mul * v) % Mod;
    }

    void update(int x) {
        f[x].sum1 = (f[f[x].l].sum1 + f[f[x].r].sum1) % Mod;
        f[x].sum2 = (f[f[x].l].sum2 + f[f[x].r].sum2) % Mod;
        f[x].sum3 = (f[f[x].l].sum3 + f[f[x].r].sum3) % Mod;
    }

    void down(int x, int l, int r) {
        if(l == r) return;
        int mid = (l + r) / 2;

        if(f[x].set != -1) {
            set(f[x].l, l, mid, f[x].set);
            set(f[x].r, mid + 1, r, f[x].set);
            f[x].set = -1;
        }

        if(f[x].mul != 1) {
            mul(f[x].l, l, mid, f[x].mul);
            mul(f[x].r, mid + 1, r, f[x].mul);
            f[x].mul = 1;
        }

        if(f[x].add != 0) {
            add(f[x].l, l, mid, f[x].add);
            add(f[x].r, mid + 1, r, f[x].add);
            f[x].add = 0;
        }
    }

    void add(int x, int l, int r, int a, int b, int v) {
        if(a <= l && r <= b) {
            down(x, l, r);
            add(x, l, r, v);
        }
        else {
            down(x, l, r);
            int mid = (l + r) / 2;
            if(b <= mid) add(f[x].l, l, mid, a, b, v);
            else if(a > mid) add(f[x].r, mid + 1, r, a, b, v);
            else {
                add(f[x].l, l, mid, a, b, v);
                add(f[x].r, mid + 1, r, a, b, v);
            }
            update(x);
        }
    }

    void mul(int x, int l, int r, int a, int b, int v) {
        if(a <= l && r <= b) {
            down(x, l, r);
            mul(x, l, r, v);
        }
        else {
            down(x, l, r);
            int mid = (l + r) / 2;
            if(b <= mid) mul(f[x].l, l, mid, a, b, v);
            else if(a > mid) mul(f[x].r, mid + 1, r, a, b, v);
            else {
                mul(f[x].l, l, mid, a, b, v);
                mul(f[x].r, mid + 1, r, a, b, v);
            }
            update(x);
        }
    }

    void set(int x, int l, int r, int a, int b, int v) {
        if(a <= l && r <= b) {
            down(x, l, r);
            set(x, l, r, v);
        }
        else {
            down(x, l, r);
            int mid = (l + r) / 2;
            if(b <= mid) set(f[x].l, l, mid, a, b, v);
            else if(a > mid) set(f[x].r, mid + 1, r, a, b, v);
            else {
                set(f[x].l, l, mid, a, b, v);
                set(f[x].r, mid + 1, r, a, b, v);
            }
            update(x);
        }
    }

    int query(int x, int l, int r, int a, int b, int op) {
        if(a <= l && r <= b) {
            if(op == 1) return f[x].sum1;
            if(op == 2) return f[x].sum2;
            if(op == 3) return f[x].sum3;
        }
        else {
            down(x, l, r);
            int mid = (l + r) / 2;
            int ans = 0;
            if(b <= mid) ans = (ans + query(f[x].l, l, mid, a, b, op)) % Mod;
            else if(a > mid) ans = (ans + query(f[x].r, mid + 1, r, a, b, op)) % Mod;
            else {
                ans = (ans + query(f[x].l, l, mid, a, b, op)) % Mod;
                ans = (ans + query(f[x].r, mid + 1, r, a, b, op)) % Mod;
            }
            update(x);
            return ans % Mod;
        }
    }
}t;

int main() {
    // freopen("C.in", "r", stdin);
    while(true){
        scanf("%d%d", &n, &m);
        if(!n && !m) break;
        t.init(1, n);
        for(int i = 0; i < m; i++) {
            int op, l, r, p;
            scanf("%d%d%d%d", &op, &l, &r, &p);
            if(op == 1) {
                t.add(t.root, 1, n, l, r, p);
            }
            else if(op == 2) {
                t.mul(t.root, 1, n, l, r, p);
            }
            else if(op == 3) {
                t.set(t.root, 1, n, l, r, p);
            }
            else if(op == 4) printf("%d\n", t.query(t.root, 1, n, l, r, p));
            //printf("%d\n", t.f[0].sum1);
        }
    }
}
[ Copy to Clipboard ]    [ Save to File]
