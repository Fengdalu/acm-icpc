#include <bits/stdc++.h>

const int N = 2000;
char s[N];
int main() {
  int n; scanf("%d%s", &n, s);
  int J = 0;
  std::string p;
  while(J < n) {
    while(J + 2 < n && s[J] == 'o' && s[J + 1] == 'g' && s[J + 2] == 'o') {
      p = p + "***";
      s[J] = '*';
      J++;
      while(J + 1 < n && s[J] == 'g' && s[J + 1] == 'o') {
        s[J] = '*'; s[J + 1] = '*'; J += 2;
      }
    }
    if(J < n) p = p + s[J];
    J++;
  }
  printf("%s\n", p.c_str());
  return 0;
}
