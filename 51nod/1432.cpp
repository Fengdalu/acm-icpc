#include <bits/stdc++.h>

#define SZ size()
#define OP begin()
using namespace std;

int main() {
  int n, x, m;
  multiset<int> s;
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%d", &x);
    s.insert(x);
  }
  int ans = 0;
  while(s.SZ) {
    int p = *s.OP; s.erase(s.OP);
    auto t = s.upper_bound(m - p);
    ans++;
    if(t == s.OP) continue;
    t--;
    s.erase(t);
  }
  printf("%d\n", ans);
  return 0;
}
