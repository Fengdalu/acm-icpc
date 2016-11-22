#include <bits/stdc++.h>

int pre[256];
int main() {
  for(int i = 0; i < 256; i++) {
    int mk = 255 & (i ^ (i << 1));
    pre[255 & (i ^ (i << 1))] = i;
  }
  int n;
  while(~scanf("%d", &n)) {
    for(int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      printf("%d ", pre[x]);
    }
    puts("");
  }
  return 0;
}

