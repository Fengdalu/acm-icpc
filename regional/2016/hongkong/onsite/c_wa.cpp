#include <bits/stdc++.h>

using namespace std;
#define PII pair<int, int>
#define MP make_pair
#define AA first
#define BB second
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

const int N = 100, STEP = 600;
int n;
double w[N], h[N], s[N][2], v[N][2], X[N<<1], Y[N<<1], W, H, e;
bool f[N<<1][N<<1];
struct rec {
  double x[2], y[2];
} a[N];

double cal(double t) {
  int cx = 0, cy = 0;
  for(int i = 0; i < n; i++) {
    rec &cur = a[i];
    double x = s[i][0] + t * v[i][0];
    double y = s[i][1] + t * v[i][1];
//    printf("%.2f %.2f %.2f %.2f\n", x, y, w[i], h[i]);
    cur.x[0] = x; cur.x[1] = x + w[i];
    cur.y[0] = y; cur.y[1] = y + h[i];
    X[cx++] = cur.x[0]; X[cx++] = cur.x[1];
    Y[cy++] = cur.y[0]; Y[cy++] = cur.y[1];
  }
  X[cx++] = 0; X[cx++] = W;
  Y[cy++] = 0; Y[cy++] = H;
  sort(X, X + cx);
  sort(Y, Y + cy);
//  printf("%d %d\n", cx, cy);
  for(int i = 0; i < n; i++) {
    rec &cur = a[i];
    int lx = lower_bound(X, X + cx, cur.x[0]) - X, rx = lower_bound(X, X + cx, cur.x[1]) - X;
    int ly = lower_bound(Y, Y + cy, cur.y[0]) - Y, ry = lower_bound(Y, Y + cy, cur.y[1]) - Y;
//    printf("%d %d %d %d\n", lx, rx, ly, ry);
    for(int j = lx; j < rx; j++) for(int k = ly; k < ry; k++) f[j][k] = true;
  }
  double ans = 0;
  int lx = lower_bound(X, X + cx, 0) - X, rx = lower_bound(X, X + cx, W) - X;
  int ly = lower_bound(Y, Y + cy, 0) - Y, ry = lower_bound(Y, Y + cy, H) - Y;
//  printf("%d %d %d %d\n", lx, rx, ly, ry);
  for(int i = lx; i < rx; i++)
    for(int j = ly; j < ry; j++) {
      if(f[i][j]) ans += (X[i + 1] - X[i]) * (Y[j + 1] - Y[j]);
//      printf("%d", 1 * f[i][j]);
//      if(j == ry - 1) printf("\n");
    }
  return ans;
}

int main() {
//  freopen("a.in", "r", stdin);
  scanf("%d%lf%lf%lf", &n, &W, &H, &e);
  for(int i = 0; i < n; i++)
    scanf("%lf%lf%lf%lf%lf%lf", &w[i], &h[i], &s[i][0], &s[i][1], &v[i][0], &v[i][1]);

  double dt = e / STEP;
//  printf("%.5f\n", cal(0));
//  return 0;
  double ans; bool flag = false;
  for(double tt = 0; tt <= e; tt += dt) {
      double l = tt, r = tt + dt;
      for(int cc = 0; cc < 50; cc++) {
        double mid = (l + r) / 2.0;
        double midmid = (l + mid) / 2.0;
        if(cal(midmid) > cal(mid)) l = midmid;
        else r = mid;
      }
      double t = cal(l);
      if(!flag || t < ans) {
        ans = t;
      }
      flag = true;
  }
  printf("%.6f\n", ans);
  return 0;
}
