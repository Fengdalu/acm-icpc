#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
#define AA first
#define BB second
#define MP make_pair
#define SZ size
#define PB push_back
#define PII pair<int, int>

const int N = 200;
int a[N];
int main() {
  int n, m; scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++) scanf("%d", a + i + 1);
  int ans = 0;
  for(int i = 0; i < m; i++) {
    int l, r; scanf("%d%d", &l, &r);
    int s = accumulate(a + l, a + r + 1, 0);
    if(s > 0) ans += s;
  }
  printf("%d\n", ans);
  return 0;
}
