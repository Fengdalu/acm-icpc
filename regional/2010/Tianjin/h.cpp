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
typedef long long ll;
#define PB(x) push_back(x)
#define SZ size()
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
struct E {
    int l, r;
    int sum;
}e[3000000];
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

int query(int a, int b, int l, int r, int k) {
    int mid = (l + r) >> 1;
    int sum = -e[e[a].l].sum + e[e[b].l].sum;
    if(l == r) return l;
    if(k <= sum) return query(e[a].l, e[b].l, l, mid, k);
    else return query(e[a].r, e[b].r, mid + 1, r, k - sum);
}
const int MQ = 300010;
int op[MQ];
int s[MQ], t[MQ], x[MQ];
int Y[MQ];
int rt[MQ];
struct BIT {
    int _[100010];
    int _SZ;
    void init(int p) {
        _SZ = p;
        memset(_, 0, sizeof _);
    }
    int lowbit(int x) { return x & (-x); }
    void insert(int p) {
        while(p < _SZ) {
            while(p < _SZ) {
                _[p]++;
                p += lowbit(p);
            }
        }
    }
    int cal(int p) {
        int tot = 0;
        while(p) {
            tot += _[p];
            p -= lowbit(p);
        }
        return tot;
    }
} T;

inline void run()  {
    static int _case = 1;
    static char buf[20];
    int m;
    if(scanf("%d", &m) != 1) exit(0);
    printf("Case %d:\n", _case++);
    int cnt = 0;
    for(int i = 0; i < m; i++) {
        scanf("%s", buf);
        if(!strcmp(buf, "Insert")) op[i] = 0;
        else if(!strcmp(buf, "Query_1")) op[i] = 1;
        else if(!strcmp(buf, "Query_2")) op[i] = 2;
        else if(!strcmp(buf, "Query_3")) op[i] = 3;
        if(op[i] == 0) {
            scanf("%d", &x[i]);
            Y[cnt++] = x[i];
        }
        else if(op[i] == 1) {
            scanf("%d%d%d", &s[i], &t[i], &x[i]);
        }
        else if(op[i] == 2) {
            scanf("%d", &x[i]);
        }
        else if(op[i] == 3) {
            scanf("%d", &x[i]);
        }
    }
    sort(Y, Y + cnt);
    cnt = unique(Y, Y + cnt) - Y;
    T.init(cnt + 1);
    tot = 0;
    int cur = 0;
    build(rt[cur], 1, cnt);
    ll ans1, ans2, ans3 ;
    ans1 = ans2 = ans3 = 0;
    for(int i = 0; i < m; i++) {
        if(op[i] == 0) {
            int pos = lower_bound(Y, Y + cnt, x[i]) - Y + 1;
            T.insert(pos);
            update(rt[cur + 1], 1, cnt, pos, rt[cur]);
            cur++;
        }
        else if(op[i] == 1) {
            ans1 += 1ll * Y[query(rt[s[i] - 1], rt[t[i]], 1, cnt, x[i]) - 1];
        }
        else if(op[i] == 2) {
            int pos = lower_bound(Y, Y + cnt, x[i]) - Y + 1;
            ans2 +=  1ll * T.cal(pos);
        }
        else if(op[i] == 3) {
            ans3 +=  1ll * Y[query(rt[0], rt[cur], 1, cnt, x[i]) - 1];
        }
    }
    cout << ans1 << endl;
    cout << ans2 << endl;
    cout << ans3 << endl;
}

int main() {
   for(;;run());
   return 0;
}
