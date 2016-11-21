#include <bits/stdc++.h>

const int N = 3e5+1000;
char s[N];
int main() {
  int n, A, b, k, a;
  scanf("%d%d%d%d", &n, &A, &b, &k);
  scanf("%s", s);
  a = 0;
  int J = 0;
  while(J < n) {
    while(s[J] == '1') J++;
    int t = 0;
    while(s[J] == '0') {J++; t++;}
    a += t / b;
  }

  std::queue<int> ans;
  J = 0;
  int tot = a - (A - 1);
  while(J < n && tot) {
    while(s[J] == '1') J++;
    int R = J;
    while(s[R] == '0') R++;
    int g = R - J; g /= b;
    for(int i = J; i < R && tot; i += b) {
        if(i + b - 1 < R) {
          tot--;
          ans.push(i + b - 1);
        }
    }
    J = R;
  }
  printf("%d\n", ans.size());
  while(ans.size()) printf("%d ", ans.front() + 1), ans.pop();
  return 0;
}
