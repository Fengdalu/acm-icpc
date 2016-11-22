#include <bits/stdc++.h>

const int N = 2e5+10000;
int a[N], b[N];

int main() {
  int n, s; scanf("%d%d", &n, &s);
  for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int ans = 0;
  if(a[s] != 0) ans++;
  for(int i = 1; i <= n; i++) if(a[i] == 0 && i != s) ans++;

  int tot = 0;
  for(int i = 0; i < n; i++) {

  }
  printf("%d\n", ans);
  return 0;
}
