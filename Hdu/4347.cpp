#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define OP begin()
#define ED end()

const int K = 5;
const int N = 1e6;
int cnt, n, k, cur;
struct point {
  LL _[K];
  LL& operator [] (int x) {
    return _[x];
  }
} a[N];

template <typename T> T SQ(T x) { return x * x; }
struct node {
  int l, r;
  point L, R, p;
  LL LB(point p) {
    LL tot = 0;
    for(int i = 0; i < k; i++) {
      tot += SQ(max(0LL, 1LL * max(L[i] - p[i], p[i] - R[i])));
    }
    return tot;
  }


} nodes[N];

LL dis(point a, point b) {
  LL tot = 0;
  for(int i = 0; i < k; i++) {
    tot += SQ(1LL * a[i] - b[i]);
  }
  return tot;
}

int newNode() {
  nodes[cnt].l = nodes[cnt].r = -1;
  return cnt++;
}

void update(node &p) {
  int t[] = {p.l, p.r};
  for(int i = 0; i < k; i++) {
    for(int j = 0; j < 2; j++) {
      int nt = t[j];
      if(nt == -1) continue;
      cmin(p.L[i], nodes[nt].L[i]);
      cmax(p.R[i], nodes[nt].R[i]);
    }
  }
}

int operator < (point a, point b) {return a[cur]<b[cur];}
void build(int &rt, int d, int l, int r) {
  int mid = (l + r) >> 1;
  rt = newNode();
  cur = d;
  nth_element(a + l, a + mid, a + r + 1);
  nodes[rt].p = nodes[rt].L = nodes[rt].R = a[mid];
  if(l < mid) build(nodes[rt].l, (d + 1) % k, l, mid - 1);
  if(mid < r) build(nodes[rt].r, (d + 1) % k, mid + 1, r);
  update(nodes[rt]);
}

void sol(int rt, point t, priority_queue< pair<LL, point> >&ans, int m) {
  ans.push(MP(dis(t, nodes[rt].p), nodes[rt].p));
  while(ans.SZ > m) ans.pop();

  int l = nodes[rt].l, r = nodes[rt].r;
  if(~l) {
    sol(l, t, ans, m);
    if(~r && (nodes[r].LB(t) < ans.top().AA || ans.SZ < m)) sol(r, t, ans, m);
  }
  else if(~r) {
    sol(r, t, ans, m);
  }
}


int main() {
//  freopen("a.in", "r", stdin);
//  freopen("1.out", "w", stdout);
  while(~scanf("%d%d", &n, &k)) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < k; j++) scanf("%I64d", &a[i][j]);
    }
    cnt = 0;
    int rt = -1;
    build(rt, 0, 0, n - 1);
    int Q; scanf("%d", &Q);
    while(Q--) {
      point tmp;
      for(int i = 0; i < k; i++) scanf("%I64d", &tmp[i]);
      int m; scanf("%d", &m);
      priority_queue<pair<LL, point> >ans;
      sol(rt, tmp, ans, m);
      vector<point> b(ans.SZ);
      int cnt = 0;
      printf("the closest %d points are:\n", ans.size());
      while(!ans.empty()) {
        b[cnt] = ans.top().BB;
        cnt++;
        ans.pop();
      }
      reverse(b.OP, b.ED);
      for(int i = 0; i < cnt; i++) {
        for(int j = 0; j < k; j++) if(j == 0) printf("%I64d", b[i][j]);
        else printf(" %I64d", b[i][j]);
        printf("\n");
      }
    }
  }
  return 0;
}
