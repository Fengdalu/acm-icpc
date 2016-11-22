#include <bits/stdc++.h>

const int N = 2e5+1000;

int n;
struct pt {
  int x, y, z;
}a[N];
int f[N];
long long ans;

int cmp1(pt a, pt b) { return a.x < b.x; }
int cmp2(pt a, pt b) { return a.y < b.y; }

int lowbit(int x) { return x & (-x); }
void add(int p, int c = 1) {
  while(p < N) {
    f[p] += c;
    p += lowbit(p);
  }
}

int cal(int p) {
  int tot = 0;
  while(p) {
    tot += f[p];
    p -= lowbit(p);
  }
  return tot;
}

void sol(int l, int r) {
  int mid = (l + r) >> 1;
  if(l < mid) sol(l, mid);
  std::sort(a + l, a + mid + 1, cmp2);
  std::sort(a + mid + 1, a + r + 1, cmp2);
  int J = l;
  for(int i = mid + 1; i <= r; i++) {
    while(J <= mid && a[J].y < a[i].y) {add(a[J].z); J++;}
    ans += 1ll * cal(a[i].z);
  }
  while(J <= mid) {add(a[J].z); J++;}
  std::sort(a + l, a + mid + 1, cmp1);
  std::sort(a + mid + 1, a + r + 1, cmp1);
  for(int i = l; i <= mid; i++) add(a[i].z, -1);
  if(mid < r) sol(mid + 1, r);
}

int main() {
  // freopen("a.in", "r", stdin);
  while(~scanf("%d", &n)) {
    for(int i = 1; i <= n; i++) {
      int x; scanf("%d", &x); x--;
      a[x].x = i;
    }
    for(int i = 1; i <= n; i++) {
      int x; scanf("%d", &x); x--;
      a[x].y = i;
    }
    for(int i = 1; i <= n; i++) {
      int x; scanf("%d", &x); x--;
      a[x].z = i;
    }

    std::sort(a, a + n, cmp1);

    ans = 0;
    sol(0, n - 1);
    printf("%lld\n", ans);
  }
  return 0;
}

