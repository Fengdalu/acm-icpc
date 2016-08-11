#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct node {
    int l, r;
    int c;
}f[8000000];
int cnt;

void insert(int &rt, ll num, int p) {
    if(rt == -1) {
        rt = ++cnt;
        f[rt].l = f[rt].r = -1;
        f[rt].c = 0;
    }
    f[rt].c++;
    if(p == -1) { return; }
    if(1ll << p & ~num) insert(f[rt].l, num, p - 1);
    else insert(f[rt].r, num, p - 1);
}

void del(int rt, ll num, int p) {
    f[rt].c--;
    if(p == -1) { return; }
    if(1ll << p & ~num) del(f[rt].l, num, p - 1);
    else del(f[rt].r, num, p - 1);
}

ll qry(int rt, ll num, int p) {
    if(rt == -1) return 0;
    if(1ll << p & num) {
        if(f[rt].l == -1 || f[f[rt].l].c == 0) return qry(f[rt].r, num, p - 1);
        else return (1ll << p) | qry(f[rt].l, num, p - 1);
    }
    else  {
        if(f[rt].r == -1 || f[f[rt].r].c == 0) return qry(f[rt].l, num, p - 1);
        else return (1ll << p) | qry(f[rt].r, num, p - 1);
    }
    return -1;
}

int main() {
    cnt = 0;
    char op[3];
    int rt = -1;
    int n;
    scanf("%d", &n);
    insert(rt, 0, 32);
    for(int i = 0; i < n; i++) {
        ll x;
        scanf("%s%I64d", op, &x);
        if(op[0] == '+') insert(rt, x, 32);
        else if(op[0] == '-') del(rt, x, 32);
        else printf("%I64d\n", qry(rt, x, 32));
    }
    return 0;
}
