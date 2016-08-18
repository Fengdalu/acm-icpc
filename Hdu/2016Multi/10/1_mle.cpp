#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> PII;
#define PB(x) push_back(x)
#define SZ size()
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
struct E {
    int l, r;
    int sum;
}e[6000000];
int rt[100010];
int X[100010];
int w[100010];
int tot;

void build(int &rt, int l, int r) {
    rt = tot++;
    e[rt].sum = 0;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(e[rt].l, l, mid);
    build(e[rt].r, mid + 1, r);
}

void update(int &rt, int l, int r, int w, int fa) {
    rt = tot++;
    e[rt].l = e[fa].l;
    e[rt].r = e[fa].r;
    e[rt].sum = e[fa].sum + 1;
    if(l == r) return ;
    int mid = (l + r) >> 1;
    if(w <= mid) update(e[rt].l, l, mid, w, e[fa].l);
    else update(e[rt].r, mid + 1, r, w, e[fa].r);
}

int query(int l1, int r1, int l2, int r2, int l, int r, int k) {
    int mid = (l + r) >> 1;
    int hf = e[e[r1].l].sum + e[e[r2].l].sum - e[e[l1].l].sum - e[e[l2].l].sum;
    if(l == r) return X[l];
    if(hf >= k) return query(e[l1].l, e[r1].l, e[l2].l, e[r2].l, l, mid, k);
    else return query(e[l1].r, e[r1].r, e[l2].r, e[r2].r, mid + 1, r, k - hf);
}

void run() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &X[i]);
        w[i] = X[i];
    }
    sort(X, X + n);
    int cnt = unique(X, X + n) - X;
    for(int i = 1; i <= n; i++) w[i] = lower_bound(X, X + cnt, w[i]) - X;
    build(rt[0], 0, cnt - 1);
    for(int i = 1; i <= n; i++) update(rt[i], 0, cnt - 1, w[i], rt[i - 1]);
    while(m--) {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        l1--; l2--; l1 = rt[l1], l2 = rt[l2], r1 = rt[r1], r2 = rt[r2];
        int sum = e[r1].sum + e[r2].sum - e[l1].sum - e[l2].sum;
        //cout << sum << endl;
        if(sum & 1) {
            printf("%.1f\n", (double)query(l1, r1, l2, r2, 0, cnt - 1, sum / 2 + 1));
        }
        else {
            double a = query(l1, r1, l2, r2, 0, cnt - 1, sum / 2);
            double b = query(l1, r1, l2, r2, 0, cnt - 1, sum / 2 + 1);
            //cout << a << " " << b << endl;
            a = (a + b) / 2.0;
            printf("%.1f\n", a);
        }
    }
}

int main() {
    int _T; scanf("%d", &_T);
    while(_T--) {
        run();
    }
    return 0;
}
