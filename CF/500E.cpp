#include <bits/stdc++.h>

const int N = 2e5+100;
int pos[N], l[N];
std::vector< std::pair<int, int> > TL[N];

typedef long long LL;
struct node {int l, r; LL cover; bool vis;} nodes[10000000];
int cnt = 0;
LL ans[N];

int newNode() {
    cnt++;
    nodes[cnt].l = nodes[cnt].r = -1;
    nodes[cnt].cover = 0;
    nodes[cnt].vis = false;
    return cnt;
}

void update(int root) {
    int l = nodes[root].l, r = nodes[root].r;
    if(nodes[root].vis) return;
    nodes[root].cover = 0;
    if(l != -1) nodes[root].cover += nodes[l].cover;
    if(r != -1) nodes[root].cover += nodes[r].cover;
}

void deal(int root, LL l, LL r) {
    nodes[root].vis = true;
    nodes[root].cover = r - l + 1;
}

void down(int root, LL L, LL R) {
    if(!nodes[root].vis) return;
    LL mid = (L + R) >> 1;
    int &l = nodes[root].l, &r = nodes[root].r;
    if(l == -1) l = newNode();
    if(r == -1) r = newNode();
    deal(l, L, mid);
    deal(r, mid + 1, R);
}

void add(int &root, LL l, LL r, LL a, LL b) {
    if(root == -1) { root = newNode(); }
    if(a <= l && r <= b) {
        deal(root, l, r);
        return;
    }
    down(root, l, r);
    LL mid = (l + r) >> 1;
    if(b <= mid) add(nodes[root].l, l, mid, a, b);
    else if(a > mid) add(nodes[root].r, mid + 1, r, a, b);
    else {
        add(nodes[root].l, l, mid, a, b);
        add(nodes[root].r, mid + 1, r, a, b);
    }
    update(root);
}

LL cal(int &root, LL l, LL r, LL a, LL b) {
    if(root == -1) { root = newNode(); }
    if(a <= l && r <= b) {
        return nodes[root].cover;
    }
    down(root, l, r);
    LL mid = (l + r) >> 1;
    if(b <= mid) return cal(nodes[root].l, l, mid, a, b);
    else if(a > mid) return cal(nodes[root].r, mid + 1, r, a, b);
    else return cal(nodes[root].l, l, mid, a, b) +
        cal(nodes[root].r, mid + 1, r, a, b);
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d%d", pos + i, l + i);
    int Q;
    scanf("%d", &Q);
    int root = -1;
    for(int i = 0; i < Q; i++) {
        int L, R;
        scanf("%d%d", &L, &R);
        L--; R--;
        TL[L].push_back(std::make_pair(R, i));
    }
    int LB = 1, RB = 2e9;
    for(int i = n - 1; i > -1; i--) {
        add(root, LB, RB, pos[i], pos[i] + l[i] - 1);
        for(auto &p : TL[i]) {
            int L = pos[i], R = pos[p.first] - 1, id = p.second;
            ans[id] = 1ll * R - L + 1ll - cal(root, LB, RB, L, R);
        }
    }
    for(int i = 0; i < Q; i++) printf("%I64d\n", ans[i]);
    return 0;
}
