#include <bits/stdc++.h>

using namespace std;
const int N = 1e5;
int a[N], b[N];
int main() {
  int n;
  while(~scanf("%d", &n)) {
      for(int i = 0; i < n; i++) scanf("%d", a + i);
      for(int i = 0; i < n; i++) b[i] = n - 1 - a[i];
      bool flag = true;
      for(int i = 0; i < n; i++) {
        int w = a[i];
        for(int j = 0; w && j < n; j++) if(i != j && b[j]) {
          b[j]--;
          w--;
        }
        if(w) flag = false;
      }
      if(flag) puts("1"); else puts("-1");
  }
  return 0;
}
