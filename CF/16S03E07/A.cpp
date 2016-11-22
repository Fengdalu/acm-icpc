#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

char buf[200010];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<std::string> s(n);
  for(int i = 0; i < n; i++) {
    scanf("%s", buf);
    s[i] = std::string(buf);
  }
  int last = 0;
  for(int Q = 0; Q < m; Q++) {
    int op; scanf("%d", &op);
    if(op == 1) {
      scanf("%s", buf);
      int len = strlen(buf);
      for(int i = 0; i < len; i++) buf[i] = 'a' + (buf[i] - 'a' + last) % 26;
      std::string S(buf);
      bool flag = false;
      for(int i = 0; i < n; i++) {
        if(S.find(s[i]) != S.npos) {flag = true; break;}
      }
      if(flag) {puts("YES"); last = Q;} else puts("NO");
    }
    else if(op == 2) {
      int p, ss; scanf("%d%d", &p, &ss);
      p = (p + last) % n;
      ss = 'a' + (ss + last) % 26;
      s[p].push_back(ss);
    }
  }
  return 0;
}
