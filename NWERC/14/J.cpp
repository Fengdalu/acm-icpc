#include <bits/stdc++.h>

using namespace std;
#define AA first
#define BB second
#define MP make_pair
#define SZ size()

char buf[10000];
int main() {

  int n;
  while(~scanf("%d", &n)) {
    map<string, int> f1, f2;
    for(int i = 0; i < n; i++) {
      scanf("%s", buf);;
      f1[string(buf)]++;
    }
    for(int i = 0; i < n; i++) {
      scanf("%s", buf);
      f2[string(buf)]++;
    }
    int ans = 0;
    for(auto &t: f1) {
      ans += min(t.second, f2[t.first]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
