#include <bits/stdc++.h>

using namespace std;

int main() {
//  freopen("a.in", "r", stdin);
  int vx[] = {1, 0, -1, 0};
  int vy[] = {0, 1, 0, -1};
  int n, m;
  char op[10];
  while(~scanf("%d%d", &m, &n)) {
    int x = 0, y = 0, d = 1;
    bool flag = true;
    for(int i = 0; i < n; i++) {
      int t;
      scanf("%s%d", op, &t);
      if(op[0] == 'T') {
        if(t == 1) d = (d + 1) % 4;
        else d = (d + 4 - 1) % 4;
      }
      else {
        x += vx[d] * t;
        y += vy[d] * t;
      }
      if(x < 0 || x > m || y < 0 || y > m) flag = false;
    }
    if(flag) printf("%d %d\n", y, x);
    else puts("-1");
  }
  return 0;
}
