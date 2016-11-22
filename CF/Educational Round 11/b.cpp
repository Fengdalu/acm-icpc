#include <bits/stdc++.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector< std::vector<int> > a(n, std::vector<int>(4));
  int cnt = 0;
  for(int i = 0; i < n && cnt < m; i++) {
    if(cnt < m) a[i][0] = ++cnt;
    if(cnt < m) a[i][3] = ++cnt;
  }
  for(int i = 0; i < n && cnt < m; i++) {
    if(cnt < m) a[i][1] = ++cnt;
    if(cnt < m) a[i][2] = ++cnt;
  }
  const int v[] = {1, 0, 2, 3};
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 4; j++)
      if(a[i][v[j]]) printf("%d ", a[i][v[j]]);
  }
  return 0;
}
