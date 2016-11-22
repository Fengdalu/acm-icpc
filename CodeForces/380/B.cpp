#include <bits/stdc++.h>

const int N = 1200;
int f[N][N];

int main() {
  int n, m; scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) scanf("%d", &f[i][j]);

  int ans = 0;
  for(int i = 0; i < n; i++) {
    bool flag = false;
    for(int j = 0; j < m; j++) {
      if(f[i][j] == 0 && flag) ans++;
      if(f[i][j]) flag = true;
    }
  }
  for(int i = 0; i < n; i++) {
    bool flag = false;
    for(int j = m - 1; j >= 0; j--) {
      if(f[i][j] == 0 && flag) ans++;
      if(f[i][j]) flag = true;
    }
  }

  for(int j = 0; j < m; j++) {
    bool flag = false;
    for(int i = 0; i < n; i++) {
      if(f[i][j] == 0 && flag) ans++;
      if(f[i][j]) flag = true;
    }
  }

  for(int j = 0; j < m; j++) {
    bool flag = false;
    for(int i = n - 1; i >= 0; i--) {
      if(f[i][j] == 0 && flag) ans++;
      if(f[i][j]) flag = true;
    }
  }
  printf("%d\n", ans);
  return 0;
}
