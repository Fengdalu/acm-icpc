#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

#define PB push_back
#define PF push_front
#define PPB pop_back
#define PPF pop_front
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define OP begin()
#define ED end()
#define SORT(x) sort(x.begin(), x.end())
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)

const double eps = 1e-8;
const LL MOD = 1000000007;
const LL INF = 0x3f3f3f3f;

#define Maxn 75
#define Maxm 75
int n, m, K;
struct Node {
    Node *L, *R, *U, *D;
    int col, row;
} *head, *row[Maxn], *col[Maxm], node[Maxn * Maxm];
int colsum[Maxm], cnt;
/* dancing link
 * 精确覆盖问题
 * 可以添加迭代加深优化：
 * 1）枚举深度h；
 * 2）若当前深度+predeep > h return false；
 *
 */
///*
int predeep() {
    bool vis[Maxm];
    memset (vis, 0, sizeof (vis) );
    int ret = 0;
    for (Node *p = head->R; p != head; p = p->R)
        if (!vis[p->col]) {
            ret ++ ;
            vis[p->col] ++ ;
            for (Node *q = p->D; q != p; q = q->D)
                for (Node *r = q->R; r != q; r = r->R)
                    vis[r->col] = true;
        }
    return ret;
}
//*/
void init (int mat[][Maxm], int n, int m) {
    cnt = 0;
    memset (colsum, 0, sizeof (colsum) );
    head = &node[cnt ++ ];
    for (int i = 1; i <= n; i ++ )
        row[i] = &node[cnt ++ ];
    for (int j = 1; j <= m; j ++ )
        col[j] = &node[cnt ++ ];

    head->D = row[1], row[1]->U = head;
    head->R = col[1], col[1]->L = head;
    head->U = row[n], row[n]->D = head;
    head->L = col[m], col[m]->R = head;
    head->row = head->col = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (i != n) row[i]->D = row[i + 1];
        if (i != 1) row[i]->U = row[i - 1];
        row[i]->L = row[i]->R = row[i];
        row[i]->row = i, row[i]->col = 0;
    }
    for (int i = 1; i <= m; i ++ ) {
        if (i != m) col[i]->R = col[i + 1];
        if (i != 1) col[i]->L = col[i - 1];
        col[i]->U = col[i]->D = col[i];
        col[i]->col = i, col[i]->row = 0;
    }
    for (int i = n; i > 0; i -- )
        for (int j = m; j > 0; j -- )
            if (mat[i][j]) {
                Node *p = &node[cnt ++ ];
                p->R = row[i]->R, row[i]->R->L = p;
                p->L = row[i], row[i]->R = p;
                p->D = col[j]->D, col[j]->D->U = p;
                p->U = col[j], col[j]->D = p;
                p->row = i;
                p->col = j;
                colsum[j] ++ ;
            }
}
//多重覆盖只需删除列，无需对应行删除
///*
void remove (Node *c) {
    for (Node *p = c->D; row[p->row] != row[c->row]; p = p->D) {
        p->R->L = p->L; p->L->R = p->R;
    }
}
void resume (Node *c) {
    for (Node * p = c->U; row[p->row] != row[c->row]; p = p->U) {
        p->L->R = p->R->L = p;
    }
}
//*/
/*
void remove(Node *c) {
    c->L->R = c->R;
    c->R->L = c->L;
    for (Node *p = c->D; p != c; p = p->D) {
        for (Node *q = p->R; q != p; q = q->R) {
            q->U->D = q->D;
            q->D->U = q->U;
            colsum[q->col] -- ;
        }
    }
}
void resume (Node *c) {
    for (Node *p = c->U; p != c; p = p->U) {
        for (Node *q = p->L; q != p; q = q->L) {
            q->U->D = q;
            q->D->U = q;
            colsum[q->col] ++ ;
        }
    }
    col[c->col]->L->R = col[c->col];
    col[c->col]->R->L = col[c->col];
}
//*/


int ans[Maxm];
int dfs (int deep) {
    if (head->R == head) return deep <= K;
    if (deep + predeep() > K) return false;
    Node *p, *q = head->R;
    for (p = head->R; p != head; p = p->R) {
        if (colsum[p->col] < colsum[q->col])
            q = p;
    }
    for (p = q->D; p != q; p = p->D) {
        remove(p);
        for (Node* r = p->R; r != p; r = r->R) {
            if (r->col != 0)
                remove (r);
        }
        /*--------可修改区域-----------*/
//       ans[deep] = p->row;
        /*-----------------------------*/
        int sta = dfs (deep + 1);
        if (sta) return sta;
        for (Node* r = p->L; r!= p; r = r->L)
            if (r->col != 0)
                resume (r);
        resume(p);
    }
    return false;
}

LL x[Maxn], y[Maxn];
LL dist[Maxn][Maxn];
int mat[Maxn][Maxn];
vector<LL> g;
bool check (LL L) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (dist[i][j] <= L) mat[i][j] = 1;
            else mat[i][j] = 0;
        }
    }
    init (mat, n, n);
    if (dfs (0) ) return true;
    else return false;
}
int main() {
    int i, j, u, v, w;
//    freopen ("in.txt", "r", stdin);
    //freopen("", "w", stdout);
    int te;
    scanf ("%d", &te);
    for (int ca = 1; ca <= te; ca++) {
        scanf ("%d%d", &n, &K);
        for (i = 1; i <= n; i++) {
            scanf ("%d%d", &u, &v);
            x[i] = u;
            y[i] = v;
        }
        g.clear();
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                dist[i][j] = abs (x[i] - x[j]) + abs (y[i] - y[j]);
                g.PB (dist[i][j]);
            }
        }
        sort (g.BG, g.ED);
        g.erase (unique (g.BG, g.ED), g.ED);
        int l = 0, r = g.SZ - 1, mid;
        while (l + 1 < r) {
            mid = (l + r) >> 1;
            if (check (g[mid]) ) r = mid;
            else l = mid + 1;
        }
        if (check (g[l])) r = l;
        printf ("Case #%d: %I64d\n", ca, g[r]);
    }
    return 0;
}

