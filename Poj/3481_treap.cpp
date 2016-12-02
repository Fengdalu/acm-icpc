#include <bits/stdc++.h>

using namespace std;
#define AA first
#define BB second
#define MP make_pair
#define PII pair<int, int>

const int N = 100000+1000, MOD = 1e9+7;
struct node {
    node* ch[2];
    int key, sz;
    PII data;
    void up() {
        sz = ch[0]->sz + ch[1]->sz;
    }
} f[N], *cur = f;
node *nil = &f[0];
node *rt = nil;

node* get(PII data) {
    cur++;
    cur->ch[0] = cur->ch[1] = nil;
    cur->sz = 1;
    cur->key = rand();
    cur->data = data;
    return cur;
}

pair<node*, node*> split(node *p, int n) {
    if(n == 0) return MP(nil, p);
    int sz = p->ch[0]->sz;
    if(n == sz) {
        node *x = p->ch[0];
        p->ch[0] = nil;
        p->up();
        return MP(x, p);
    }
    else if(n == sz + 1) {
        node *x = p->ch[1];
        p->ch[1] = nil;
        p->up();
        return MP(p, x);
    }
    else if(n < sz) {
        pair<node*, node*> res = split(p->ch[0], n);
        p->ch[0] = res.BB;
        p->up();
        return MP(res.AA, p);
    }
    else {
        pair<node*, node*> res = split(p->ch[0], n - sz - 1);
        p->ch[1] = res.AA;
        p->up();
        return MP(p, res.BB);
    }
}

node* merge(node *p, node *q) {
    if(p == nil) return q;
    if(q == nil) return p;
    if(p->key > q->key) {
        q->ch[0] = merge(p, q->ch[0]);
        q->up();
        return q;
    }
    else {
        p->ch[1] = merge(p->ch[1], q);
        p->up();
        return p;
    }
}

int getrank(node *p, int w) {
    int ans = 0;
    while(p != nil) {
        if(w == p->data.BB) return ans + p->ch[0]->sz;
        if(w < p->data.BB) p = p->ch[0];
        else {
            ans += p->ch[0]->sz + 1;
            p = p->ch[1];
        }
    }
    return ans;
}

PII small() {
    if(rt->sz == 0) return MP(0, 0);
    pair<node*, node*> cur = split(rt, 1);
    rt = cur.BB;
    return cur.AA->data;
}

PII big() {
    if(rt->sz == 0) return MP(0, 0);
    pair<node*, node*> cur = split(rt, rt->sz - 1);
    rt = cur.AA;
    return cur.BB->data;
}

int main() {
    freopen("a.in", "r", stdin);

    while(true) {
        int op;
        scanf("%d", &op);
//        printf("OP: %d\n", op);
        if(op == 0) break;
        if(op == 1) {
            PII data; scanf("%d%d", &data.AA, &data.BB);
            node *cur = get(data);
            int rk = getrank(rt, data.BB);
            pair<node*, node*> t = split(rt, rk);
            rt = merge(t.AA, cur);
            rt = merge(rt, t.BB);
        }
        else if(op == 2) {
            PII res = big();
            printf("%d\n", res.AA);
        }
        else {
            PII res = small();
            printf("%d\n", res.AA);
        }
    }
    return 0;
}
