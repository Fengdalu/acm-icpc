#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;

const int Maxm = 5000000;
struct node {
    LL sum, c;
    int l, r;
}f[Maxm];
int cnt;

int Node(int sum, int c) {
    f[cnt].sum = sum;
    f[cnt].c = c;
    f[cnt].l = f[cnt].r = -1;
    return cnt++;
}

void update(int x) {
    if(f[x].l == -1 && f[x].r == -1) return;
    else if(f[x].l == -1)
    {
        f[x].c = f[f[x].r].c;
        f[x].sum = f[f[x].r].sum;
    }
    else if(f[x].r == -1) {
        f[x].c = f[f[x].l].c;
        f[x].sum = f[f[x].l].sum;
    }
    else if(f[f[x].l].c == f[f[x].r].c) {
        f[x].c = f[f[x].l].c;
        f[x].sum = f[f[x].l].sum + f[f[x].r].sum;
    }
    else if(f[f[x].l].c > f[f[x].r].c) {
        f[x].c = f[f[x].l].c;
        f[x].sum = f[f[x].l].sum;
    }
    else {
        f[x].c = f[f[x].r].c;
        f[x].sum = f[f[x].r].sum;
    }
}

int merge(int x, int y) {
    if(x == -1) return y;
    if(y == -1) return x;
    if(f[x].l == -1 && f[x].r == -1) {
        int p = Node(f[x].sum, f[x].c + f[y].c);
        return p;
    }
    else {
        int p = Node(0, 0);
        f[p].l = merge(f[x].l, f[y].l);
        f[p].r = merge(f[x].r, f[y].r);
        update(p);
        return p;
    }
}
const int Maxn = 100010;
vector<int>G[Maxn];
LL c[Maxn];
int rt[Maxn];
LL ans[Maxn];
int n;

int insert(int x, int a, int b, int c) {

    if(x == -1) {
        x = Node(0, 0);
    }
    if(a == b) { f[x].c++; f[x].sum = c;  }
    else {
        int mid = (a + b) / 2;
        if(c <= mid) f[x].l = insert(f[x].l, a, mid, c);
        else f[x].r = insert(f[x].r, mid + 1, b, c);
        update(x);
    }

    return x;
}

void PP(int x, int a, int b) {
    if(a == b) {
        cout << "[" << a << ", " << b << "]";
        cout << f[x].sum << " " << f[x].c << ", ";
    }
    else {
        cout << "[" << a << ", " << b << "]";
        cout << f[x].sum << " " << f[x].c << ", ";
        int mid = (a + b) / 2;
        PP(f[x].l, a, mid);
        PP(f[x].r, mid + 1, b);

    }
}


void dfs(int x, int fa) {
    for(int i = 0; i < G[x].size(); i++) if(fa != G[x][i]) {
        dfs(G[x][i], x);
    }
    rt[x] = -1;
    for(int i = 0; i < G[x].size(); i++) if(fa != G[x][i]) {
        rt[x] = merge(rt[x], rt[G[x][i]]);
    }
    //cout << f[rt[x]].sum << endl;
    rt[x] = insert(rt[x], 1, n, c[x]);
    //cout << "X: "  << x << endl;
    //PP(rt[x], 1, n);
    //cout << endl;
    ans[x] = f[rt[x]].sum;
}

int main() {
    //freopen("input.txt", "r", stdin);
    cnt = 0;
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> c[i];

    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1, -1);
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}