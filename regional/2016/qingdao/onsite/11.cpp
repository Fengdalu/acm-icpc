#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

const int N = 1000000;
struct point {
  LL _[2], op, p;
  LL& operator [] (int x) { return _[x]; }
  int operator < (const point &t) const {
    return p < t.p;
  }
} a[N], ans[N];

template <typename T> inline T SQ(T x) { return x * x; }
inline LL dis(point a, point b) {
  return SQ(1LL * (a[0] - b[0])) + SQ(1LL * (a[1] - b[1]));
}
struct node {
  int l, r, fa;
  bool vis, has;
  point p;
} b[N];
int n, m, cnt;

inline int getnode() {
  assert(cnt < N);
  b[cnt].l = b[cnt].r = -1;
  b[cnt].vis = b[cnt].has = false;
  b[cnt].fa = -1;
  return cnt++;
}

void sol(int u, point pt, point& ans, LL &value, int d) {
  if(u == -1 || !b[u].has) return;
  if(b[u].vis) {
    LL w1 = dis(b[u].p, pt);
    if(w1 < value || (w1 == value && b[u].p.op < ans.op)) {
      ans = b[u].p;
      value = w1;
    }
  }
  int l = b[u].l, r = b[u].r;
  if(pt[d] > b[u].p[d]) swap(l, r);
  sol(l, pt, ans, value, d ^ 1);
  if(1LL * SQ(pt[d] - b[u].p[d]) <= value)
    sol(r, pt, ans, value, d ^ 1);
}

void build(int &u, int l, int r, int d, int fa=-1) {

  int mid = l;
  if(l != r) mid += rand() % (r - l);
  point p = a[mid];
  swap(a[r], a[mid]);
  int j = l;
  for(int i = l; i < r; i++)
    if(a[i][d] < p[d]) {
      swap(a[i], a[j++]);
    }
  swap(a[j], a[r]);
  u = getnode();
  b[u].fa = fa;
  b[u].p = a[j];

  if(l < j) build(b[u].l, l, j - 1, d ^ 1, u);
  if(j < r) build(b[u].r, j + 1, r, d ^ 1, u);
}

void add(int u, point p, int d) {
  if(u == -1) return;
  if(b[u].p[0] == p[0] && b[u].p[1] == p[1]) {
    b[u].has = b[u].vis = true;
    return ;
  }
  if(p[d] > b[u].p[d]) add(b[u].r, p, d ^ 1);
  else add(b[u].l, p, d ^ 1);
  b[u].has |= b[u].vis;
  if(~b[u].l) b[u].has |= b[b[u].l].has;
  if(~b[u].r) b[u].has |= b[b[u].r].has;
}

int main() {
  srand((unsigned)233);
  int T;
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
      scanf("%I64d%I64d%d", &a[i][0], &a[i][1], &a[i].p);
      a[i].op = i;
    }
    cnt = 0;
    int rt = -1;
    build(rt, 0, n - 1, 0, -1);
    for(int i = n; i < m + n; i++) {
      scanf("%I64d%I64d%d", &a[i][0], &a[i][1], &a[i].p);
      a[i].op = i;
    }
    sort(a, a + n);
    sort(a + n, a + n + m);
    int j = 0;
    for(int i = n; i < n + m; i++) {
      while(j < n && a[j].p <= a[i].p) {
        add(rt, a[j], 0);
        j++;
      }
      point cur = a[i];
      int id = cur.op - n;
      ans[id][0] = ans[id][1] = 1e6;
      LL value = dis(ans[id], a[i]);
      sol(rt, a[i], ans[id], value, 0);
    }
    for(int i = 0; i < m; i++) {
      printf("%I64d %I64d %d\n", ans[i][0], ans[i][1], ans[i].p);
    }
  }
  return 0;
}
