#include <bits/stdc++.h>


using namespace std;
#define PB push_back
#define SZ size()
#define cmax(x, y) x = max(x, y)
#define OP begin()
#define ED end()

int main() {
  int n, ans = 1, x;
  scanf("%d", &n);
  vector<int> q;
  for(int i = 0; i < n; i++) {
    scanf("%d", &x);
    int p = upper_bound(q.OP, q.ED, x) - q.OP;
    cmax(ans, p + 1);
    if(p == q.SZ) q.PB(x);
    else q[p] = x;
  }
  printf("%d\n", ans);
  return 0;
}
