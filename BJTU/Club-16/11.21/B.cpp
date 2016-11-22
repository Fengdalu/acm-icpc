#include <bits/stdc++.h>

#define PII std::pair<int, int>
#define AA first
#define BB second
#define MP std::make_pair

const int N = 1e6;
std::pair<double, int> f[N];

int cmp(std::pair<double, int> a, std::pair<double, int> b) {
  return a.second > b.second;
}
int main() {
  int n, m, k;
  while(~scanf("%d%d%d", &n, &m, &k)) {
    for(int i = 0; i < m; i++) f[i].first = 0;
    for(int i = 0; i < m; i++) f[i].second = i;
    for(int i = 0; i < n; i++) {
      double x;
      for(int j = 0; j < m; j++) {
        scanf("%lf", &x);
        f[j].first -= x;
      }
    }
    std::sort(f, f + m); std::sort(f, f + k, cmp);
    for(int i = 0; i < k; i++) {
      if(i == 0) printf("%d", f[i].second + 1);
      else printf(" %d", f[i].second + 1);
    }
    puts("");
  }
  return 0;
}
