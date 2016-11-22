#include <bits/stdc++.h>

char s[200];
int main() {
  scanf("%s", s);
  int len = strlen(s);
  std::vector<int> a;
  a.push_back(0);
  for(int i = 0; i < len; i++)
    if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y') 
      a.push_back(i + 1);
  a.push_back(len + 1);
  int ans = -100;
  for(int i = 0; i < a.size() - 1; i++) {
    ans = std::max(a[i + 1] - a[i], ans);
  }
  printf("%d\n", ans);
  return 0;
}
